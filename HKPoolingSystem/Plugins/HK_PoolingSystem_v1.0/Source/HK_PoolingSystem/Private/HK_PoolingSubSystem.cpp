// Fill out your copyright notice in the Description page of Project Settings.


#include "HK_PoolingSubSystem.h"
#include "HK_PoolingSettings.h"

DEFINE_LOG_CATEGORY(HK_Pooling)

bool UHK_PoolingSubSystem::DoesSupportWorldType(const EWorldType::Type WorldType) const
{
	switch (WorldType)
	{
	case EWorldType::None:
		return false;
	case EWorldType::Game:
		return true;
	case EWorldType::Editor:
		return false;
	case EWorldType::PIE:
		return true;
	case EWorldType::EditorPreview:
		return false;
	case EWorldType::GamePreview:
		return true;
	case EWorldType::GameRPC:
		return true;
	case EWorldType::Inactive:
		return false;
	}
	UE_LOG(HK_Pooling, Warning, TEXT("Pooling Subsystem start"));

	return Super::DoesSupportWorldType(WorldType);
}

void UHK_PoolingSubSystem::Deinitialize()
{
	const UHK_PoolingSettings* Settings = GetDefault<UHK_PoolingSettings>();

	if (!Settings || !Settings->bClearOnEndPlay)
		return;

	for (TPair<UClass*, FPoolData> objectPool : Pool)
	{
		FPoolData PoolData = objectPool.Value;
		TArray<AActor*> AllActors = PoolData.Active;
		AllActors.Append(PoolData.InActive);
		for (AActor* Actor : AllActors)
		{
			if (IsValid(Actor))
			{
				Actor->Destroy();
			}
		}
	}
	Super::Deinitialize();
}

void UHK_PoolingSubSystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);

	const UHK_PoolingSettings* poolingSettings = GetDefault<UHK_PoolingSettings>();
	bDestroyOnEnd = poolingSettings->bClearOnEndPlay;

	for (TPair<UClass*, FObjectPoolSetting> objectPool : poolingSettings->ActorsToPool)
	{
		UClass* objectClass = objectPool.Key;
		if (!IsValid(objectClass))
		{
			continue;
		}

		if (!objectClass->ImplementsInterface(UHK_Poolable::StaticClass()))
		{
			UE_LOG(HK_Pooling, Warning, TEXT("Initialize :: Skipping class %s it does not implement the correct interface"), *objectClass->GetName());
			continue;
		}

		FObjectPoolSetting objectSettings = objectPool.Value;

		FPoolData& objectInPoolArray = Pool.FindOrAdd(objectClass);
		objectInPoolArray.bCanExtend = objectSettings.bCanExtend;
		objectInPoolArray.maxActorNum = objectSettings.InitialNumberToSpawn;
		objectInPoolArray.bTickEnabledOnSpawn = objectSettings.bChangeTickState;
		objectInPoolArray.bCollisionEnabledOnSpawn = objectSettings.bChangeCollisionState;

		if (objectInPoolArray.Num() >= objectInPoolArray.maxActorNum) continue;

		int maxCount = objectInPoolArray.maxActorNum - objectInPoolArray.Num();
		for (int i = 0; i < maxCount; i++)
		{
			AActor* SpawnedActor = SpawnNewActor<AActor>(objectClass, FVector::ZeroVector, FRotator::ZeroRotator);
			if (!SpawnedActor)
			{
				UE_LOG(HK_Pooling, Warning, TEXT("Initialize :: Skipping class %s Could not spawn actor"), *objectClass->GetName());
				continue;
			}

			if(!SpawnedActor->IsActorInitialized())
				UE_LOG(HK_Pooling, Warning, TEXT("Initialize :: Actor not initialized"));

			SetActorState(SpawnedActor, &objectInPoolArray, false);

			IHK_Poolable::Execute_OnDespawnFromPool(SpawnedActor);

			objectInPoolArray.InActive.AddUnique(SpawnedActor);

			UE_LOG(HK_Pooling, Warning, TEXT("Initialize :: Added %s to pool of class %s with updated count of %i."), *SpawnedActor->GetName(), *objectClass->GetName(), Pool.FindOrAdd(objectClass).Num());
		}

	}
}

bool UHK_PoolingSubSystem::SpawnFromPool(TSubclassOf<AActor> PoolClass, FVector Location, FRotator Rotation, AActor*& SpawnedActor)
{
	if (!PoolClass->ImplementsInterface(UHK_Poolable::StaticClass()))
	{
		UE_LOG(HK_Pooling, Warning, TEXT("SpawnFromPool :: Actor of class %s does not implement the proper interface!"), *PoolClass->GetName());
		return false;
	}

	FPoolData& ObjectPool = Pool.FindOrAdd(PoolClass);

	if (!ObjectPool.IsEmpty())
	{
		if (ObjectPool.HasInactiveActor())
		{
			AActor* pulledActor = nullptr;

			//Get one of the inactive actors
			for (auto object : ObjectPool.InActive)
			{
				if (IsValid(object))
				{
					pulledActor = object;
					SpawnedActor = pulledActor;
					SpawnedActor->SetActorLocationAndRotation(Location, Rotation);
					ObjectPool.InActive.Remove(pulledActor);
					ObjectPool.Active.AddUnique(pulledActor);
					UE_LOG(HK_Pooling, Warning, TEXT("SpawnFromPool :: Got from inactive!"), *PoolClass->GetName());
					break;
				}
			}
			if (pulledActor)
			{
				SetActorState(pulledActor, &ObjectPool, true);
				IHK_Poolable::Execute_OnSpawnFromPool(pulledActor);
				return true;
			}
		}

		if (!ObjectPool.bCanExtend && ObjectPool.Active.Num() > 0 && !ObjectPool.CanAddActor())
		{
			AActor* OldestActor = ObjectPool.Active[0];
			ObjectPool.Active.Remove(OldestActor);
			SetActorState(OldestActor, &ObjectPool, false);
			IHK_Poolable::Execute_OnDespawnFromPool(OldestActor);

			UE_LOG(HK_Pooling, Warning, TEXT("SpawnFromPool :: Replaced Actor!"), *PoolClass->GetName());

			SpawnedActor = OldestActor;
			SpawnedActor->SetActorLocationAndRotation(Location, Rotation);
			ObjectPool.Active.AddUnique(SpawnedActor);
			SetActorState(SpawnedActor, &ObjectPool, true);
			IHK_Poolable::Execute_OnSpawnFromPool(SpawnedActor);
			return true;
		}
	}

	SpawnedActor = SpawnNewActor<AActor>(PoolClass, Location, Rotation);
	ObjectPool.Active.AddUnique(SpawnedActor);
	SetActorState(SpawnedActor, &ObjectPool, true);
	IHK_Poolable::Execute_OnSpawnFromPool(SpawnedActor);
	return true;
}

void UHK_PoolingSubSystem::ReturnToPool(AActor* Poolable)
{
	if (!Poolable)
	{
		UE_LOG(HK_Pooling, Warning, TEXT("ReturnToPool :: Called with a null actor."));
		return;
	}

	UClass* PoolClass = Poolable->GetClass();

	if (!PoolClass)
	{
		UE_LOG(HK_Pooling, Warning, TEXT("ReturnToPool :: Actor has no valid class."));
		Poolable->Destroy();
		return;
	}

	if (PoolClass->ImplementsInterface(UHK_Poolable::StaticClass()))
	{
		FPoolData& ObjectPool = Pool.FindOrAdd(PoolClass);

		ObjectPool.Active.Remove(Poolable);
		ObjectPool.InActive.AddUnique(Poolable);

		SetActorState(Poolable, &ObjectPool, false);

		IHK_Poolable::Execute_OnDespawnFromPool(Poolable);
	}
	else
	{
		UE_LOG(HK_Pooling, Warning, TEXT("ReturnToPool :: %s does not implement the correct interface. Destroying actor %s"), *PoolClass->GetName(), *Poolable->GetName());
		Poolable->Destroy();
	}
}

void UHK_PoolingSubSystem::SetActorState(AActor* actorToChange, FPoolData* Pooldata, bool active)
{
	actorToChange->SetActorHiddenInGame(!active);

	if (Pooldata->bCollisionEnabledOnSpawn)
		actorToChange->SetActorEnableCollision(active);

	if(Pooldata->bTickEnabledOnSpawn)
		actorToChange->SetActorTickEnabled(active);
}


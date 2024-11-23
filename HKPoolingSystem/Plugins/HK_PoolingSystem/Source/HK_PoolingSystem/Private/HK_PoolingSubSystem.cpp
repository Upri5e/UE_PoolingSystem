// Fill out your copyright notice in the Description page of Project Settings.


#include "HK_PoolingSubSystem.h"

void UHK_PoolingSubSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogTemp, Warning, TEXT("Pooling Subsystem init"));
}

bool UHK_PoolingSubSystem::SpawnFromPool(TSubclassOf<AActor> PoolClass, FVector Location, FRotator Rotation, AActor*& SpawnedActor)
{
	if (!PoolClass->ImplementsInterface(UHK_Poolable::StaticClass()))
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor of class %s does not implement the proper interface!"), *PoolClass->GetName());
		return false;
	}

	FPoolArray& ObjectPool = ObjectPools.FindOrAdd(PoolClass);

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
					break;
				}
			}
			if (pulledActor)
			{
				IHK_Poolable::Execute_OnSpawnFromPool(pulledActor);
				return true;
			}
		}

		if (!ObjectPool.bCanExtend && ObjectPool.Active.Num() > 0 && !ObjectPool.CanAddActor())
		{
			AActor* OldestActor = ObjectPool.Active[0];
			ObjectPool.Active.Remove(OldestActor);

			UE_LOG(LogTemp, Warning, TEXT("Replace actor %s to spawn %s"), *OldestActor->GetName(), *PoolClass->GetName());

			SpawnedActor = OldestActor;
			SpawnedActor->SetActorLocationAndRotation(Location, Rotation);
			IHK_Poolable::Execute_OnSpawnFromPool(SpawnedActor);
			ObjectPool.Active.AddUnique(SpawnedActor);
			return true;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Number of pools %i"), ObjectPools.Num());

	SpawnedActor = SpawnNewActor<AActor>(PoolClass, Location, Rotation);
	ObjectPool.Active.AddUnique(SpawnedActor);
	IHK_Poolable::Execute_OnSpawnFromPool(SpawnedActor);

	return true;
}


void UHK_PoolingSubSystem::ReturnToPool(AActor* Poolable)
{
	if (!Poolable)
	{
		UE_LOG(LogTemp, Warning, TEXT("ReturnToPool called with a null actor."));
		return;
	}

	UClass* PoolClass = Poolable->GetClass();

	if (!PoolClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("ReturnToPool: Actor has no valid class."));
		Poolable->Destroy();
		return;
	}

	if (PoolClass->ImplementsInterface(UHK_Poolable::StaticClass()))
	{
		FPoolArray& ObjectPool = ObjectPools.FindOrAdd(PoolClass);

		ObjectPool.Active.Remove(Poolable);
		ObjectPool.InActive.AddUnique(Poolable);

		//TODO::Reset actor position and everything here

		IHK_Poolable::Execute_OnDespawnFromPool(Poolable);
	}
	else
	{
		Poolable->Destroy();
	}
}


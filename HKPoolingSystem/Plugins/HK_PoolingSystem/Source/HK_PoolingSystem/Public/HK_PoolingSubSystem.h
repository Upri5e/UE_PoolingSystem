// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HK_Poolable.h"
#include "Subsystems/WorldSubsystem.h"
#include "HK_PoolingSubSystem.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(HK_Pooling, Log, All)

USTRUCT()
struct FPoolData {

	GENERATED_USTRUCT_BODY()

public:

	//Key is active actors and value is inactive actors
	TArray<AActor*> InActive;
	TArray<AActor*> Active;

	int maxActorNum = 3;

	bool bCanExtend = true;
	bool bTickEnabledOnSpawn = true;
	bool bCollisionEnabledOnSpawn = true;

	bool IsEmpty()
	{
		return InActive.Num() + Active.Num() == 0;
	}
	bool HasInactiveActor()
	{
		return InActive.Num() > 0;
	}
	bool CanAddActor()
	{
		return InActive.Num() + Active.Num() < maxActorNum;
	}
	int Num()
	{
		return InActive.Num() + Active.Num();
	}
};
/**
 *
 */
UCLASS(Blueprintable)
class HK_POOLINGSYSTEM_API UHK_PoolingSubSystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	virtual bool DoesSupportWorldType(const EWorldType::Type WorldType) const override;

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	void OnWorldBeginPlay();

	UFUNCTION(BlueprintCallable, Category = "Pooling Subsystem", meta = (DeterminesOutputType = "PoolClass", DynamicOutputParam = "SpawnedActor"))
	bool SpawnFromPool(TSubclassOf<AActor> PoolClass, FVector Location, FRotator Rotation, AActor*& SpawnedActor);

	template <typename T>
	T* SpawnNewActor(TSubclassOf<AActor> PoolClass, FVector Location, FRotator Rotation);

	UFUNCTION(BlueprintCallable, Category = "Pooling Subsystem")
	void ReturnToPool(AActor* Poolable);

	UPROPERTY()
	TMap<UClass*, FPoolData> Pool;

	UFUNCTION(BlueprintCallable, Category = "Pooling Subsystem")
	int GetClassCountInPool() {
		return Pool.Num();
	}
private:

	bool bDestroyOnEnd = false;

	void SetActorState(AActor* actorToChange, FPoolData* Pooldata, bool active);
};

template <typename T>
T* UHK_PoolingSubSystem::SpawnNewActor(TSubclassOf<AActor> PoolClass, FVector Location, FRotator Rotation)
{
	if (!IsValid(PoolClass))
	{
		UE_LOG(HK_Pooling, Warning, TEXT("SpawnActor :: Invalid class %s"), *PoolClass->GetName());
		return nullptr;
	}
	T* PooledActor = nullptr;

	if (PoolClass.Get()->ImplementsInterface(UHK_Poolable::StaticClass()))
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		PooledActor = GetWorld()->SpawnActor<T>(PoolClass, Location, Rotation, SpawnParams);
	}

	return PooledActor;
}
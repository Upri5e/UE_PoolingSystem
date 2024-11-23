// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HK_Poolable.h"
#include "Subsystems/WorldSubsystem.h"
#include "HK_PoolingSubSystem.generated.h"

USTRUCT()
struct FPoolArray {

	GENERATED_USTRUCT_BODY()

public:

	//Key is active actors and value is inactive actors
	TArray<AActor*> InActive;
	TArray<AActor*> Active;

	int maxActorNum = 5;

	bool bCanExtend = true;

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
};
/**
 * 
 */
UCLASS(Blueprintable)
class HK_POOLINGSYSTEM_API UHK_PoolingSubSystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "Pooling Subsystem", meta = (DeterminesOutputType = "PoolClass", DynamicOutputParam="SpawnedActor"))
	bool SpawnFromPool(TSubclassOf<AActor> PoolClass, FVector Location, FRotator Rotation, AActor*& SpawnedActor);

	template <typename T>
	T* SpawnNewActor(TSubclassOf<AActor> PoolClass, FVector Location, FRotator Rotation);

	UFUNCTION(BlueprintCallable, Category = "Pooling Subsystem")
	void ReturnToPool(AActor* Poolable);

	UPROPERTY()
	TMap<UClass*, FPoolArray> ObjectPools;
};

template <typename T>
T* UHK_PoolingSubSystem::SpawnNewActor(TSubclassOf<AActor> PoolClass, FVector Location, FRotator Rotation)
{
	T* PooledActor = nullptr;

	if (PoolClass.Get()->ImplementsInterface(UHK_Poolable::StaticClass()))
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		PooledActor = GetWorld()->SpawnActor<T>(PoolClass, Location, Rotation, SpawnParams);
	}
	return PooledActor;
}
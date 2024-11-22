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
	TArray<AActor*> ObjectPool;

	bool IsEmpty() 
	{
		return ObjectPool.Num() == 0;
	}

	AActor* Pop()
	{
		return ObjectPool.Pop();
	}

	void Add(AActor* ActorToAdd)
	{
		ObjectPool.Add(ActorToAdd);
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
	void SpawnFromPool(TSubclassOf<AActor> PoolClass, FVector Location, FRotator Rotation, AActor*& SpawnedActor);

	template <typename T>
	T* SpawnFromPool(TSubclassOf<AActor> PoolClass, FVector Location, FRotator Rotation);


	UFUNCTION(BlueprintCallable, Category = "Pooling Subsystem")
	void ReturnToPool(AActor* Poolable);

	UPROPERTY()
	TMap<UClass*, FPoolArray> ObjectPools;

};

template <typename T>
T* UHK_PoolingSubSystem::SpawnFromPool(TSubclassOf<AActor> PoolClass, FVector Location, FRotator Rotation)
{
	T* PooledActor = nullptr;

	if (PoolClass.Get()->ImplementsInterface(UHK_Poolable::StaticClass()))
	{
		FPoolArray& ObjectPool = ObjectPools.FindOrAdd(PoolClass);

		if (ObjectPool.IsEmpty())
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			PooledActor = GetWorld()->SpawnActor<T>(PoolClass, Location, Rotation, SpawnParams);
		}
		else
		{
			PooledActor = CastChecked<T>(ObjectPool.Pop());
			PooledActor->SetActorLocationAndRotation(Location, Rotation);
		}
		IHK_Poolable::Execute_OnSpawnFromPool(PooledActor);
	}
	return PooledActor;
}
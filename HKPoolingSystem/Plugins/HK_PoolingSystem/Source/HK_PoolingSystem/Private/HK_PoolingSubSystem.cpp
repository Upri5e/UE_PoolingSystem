// Fill out your copyright notice in the Description page of Project Settings.


#include "HK_PoolingSubSystem.h"

void UHK_PoolingSubSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogTemp, Warning, TEXT("Pooling Subsystem init"));
}

void UHK_PoolingSubSystem::SpawnFromPool(TSubclassOf<AActor> PoolClass, FVector Location, FRotator Rotation, AActor*& SpawnedActor)
{
	SpawnedActor = SpawnFromPool<AActor>(PoolClass, Location, Rotation);
}

void UHK_PoolingSubSystem::ReturnToPool(AActor* Poolable)
{
	UClass* PoolClass = Poolable->GetClass();
	if (PoolClass->ImplementsInterface(UHK_Poolable::StaticClass()))
	{
		IHK_Poolable::Execute_OnDespawnFromPool(Poolable);
		FPoolArray* ObjectPool = ObjectPools.Find(PoolClass);
		ObjectPool->Add(Poolable);
	}
	else
	{
		Poolable->Destroy();
	}
}


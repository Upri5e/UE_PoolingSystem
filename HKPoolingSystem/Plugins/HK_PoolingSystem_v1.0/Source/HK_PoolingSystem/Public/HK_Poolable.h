// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HK_Poolable.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UHK_Poolable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class HK_POOLINGSYSTEM_API IHK_Poolable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Poolable")
	void OnSpawnFromPool();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Poolable")
	void OnDespawnFromPool();
};

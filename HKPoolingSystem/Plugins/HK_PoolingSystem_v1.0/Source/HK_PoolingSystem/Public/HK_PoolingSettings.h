// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "HK_PoolingSettings.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FObjectPoolSetting
{

	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Actor Settings", meta = (ClampMin = "0", UIMin = "0"))
	int InitialNumberToSpawn = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Actor Settings")
	bool bCanExtend = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Actor Settings", meta = (ToolTip = "Tick will be enabled when spawned and disabled when despawned"))
	bool bChangeTickState = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Actor Settings", meta = (ToolTip = "Collision will be enabled when spawned and disabled when despawned"))
	bool bChangeCollisionState = true;
};
/**
 * 
 */
UCLASS(Config = Game, defaultconfig, meta = (DisplayName = "Pooling System"))
class HK_POOLINGSYSTEM_API UHK_PoolingSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:

	virtual FName GetCategoryName() const override { return TEXT("Plugins"); };
	virtual FName GetContainerName() const override { return TEXT("Project"); };
	virtual FName GetSectionName() const override { return TEXT("PoolingSystem"); };

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Default", meta = (ToolTip = "If set to <= 0 there will be no limit"))
	int MaxObjectCountInPool = 0;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Default")
	bool bCanExtend = true;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Default")
	bool bChangeTickState = true;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Default")
	bool bChangeCollisionState = true;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Actor Settings", meta=(ToolTip="Clear and destroy all actors OnEndPlay"))
	bool bClearOnEndPlay = true;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Actor Settings")
	TMap<UClass*, FObjectPoolSetting> ActorsToPool;


};

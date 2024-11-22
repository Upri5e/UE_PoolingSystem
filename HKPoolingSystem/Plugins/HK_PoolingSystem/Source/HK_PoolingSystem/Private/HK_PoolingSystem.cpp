// Copyright Epic Games, Inc. All Rights Reserved.

#include "HK_PoolingSystem.h"

#define LOCTEXT_NAMESPACE "FHK_PoolingSystemModule"


DEFINE_LOG_CATEGORY_STATIC(PoolingSystem, All, All)

void FHK_PoolingSystemModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	UE_LOG(PoolingSystem, Log, TEXT("Pooling has been loaded!"));
}

void FHK_PoolingSystemModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

IMPLEMENT_MODULE(FHK_PoolingSystemModule, PoolingSystem)

#undef LOCTEXT_NAMESPACE

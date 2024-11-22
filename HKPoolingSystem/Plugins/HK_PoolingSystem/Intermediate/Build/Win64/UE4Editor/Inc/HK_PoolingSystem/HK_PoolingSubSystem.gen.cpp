// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HK_PoolingSystem/Public/HK_PoolingSubSystem.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHK_PoolingSubSystem() {}
// Cross Module References
	HK_POOLINGSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FPoolArray();
	UPackage* Z_Construct_UPackage__Script_HK_PoolingSystem();
	HK_POOLINGSYSTEM_API UClass* Z_Construct_UClass_UHK_PoolingSubSystem_NoRegister();
	HK_POOLINGSYSTEM_API UClass* Z_Construct_UClass_UHK_PoolingSubSystem();
	ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
class UScriptStruct* FPoolArray::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern HK_POOLINGSYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FPoolArray_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FPoolArray, Z_Construct_UPackage__Script_HK_PoolingSystem(), TEXT("PoolArray"), sizeof(FPoolArray), Get_Z_Construct_UScriptStruct_FPoolArray_Hash());
	}
	return Singleton;
}
template<> HK_POOLINGSYSTEM_API UScriptStruct* StaticStruct<FPoolArray>()
{
	return FPoolArray::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FPoolArray(FPoolArray::StaticStruct, TEXT("/Script/HK_PoolingSystem"), TEXT("PoolArray"), false, nullptr, nullptr);
static struct FScriptStruct_HK_PoolingSystem_StaticRegisterNativesFPoolArray
{
	FScriptStruct_HK_PoolingSystem_StaticRegisterNativesFPoolArray()
	{
		UScriptStruct::DeferCppStructOps<FPoolArray>(FName(TEXT("PoolArray")));
	}
} ScriptStruct_HK_PoolingSystem_StaticRegisterNativesFPoolArray;
	struct Z_Construct_UScriptStruct_FPoolArray_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPoolArray_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HK_PoolingSubSystem.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPoolArray_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPoolArray>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPoolArray_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_HK_PoolingSystem,
		nullptr,
		&NewStructOps,
		"PoolArray",
		sizeof(FPoolArray),
		alignof(FPoolArray),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FPoolArray_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPoolArray_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPoolArray()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FPoolArray_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_HK_PoolingSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("PoolArray"), sizeof(FPoolArray), Get_Z_Construct_UScriptStruct_FPoolArray_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FPoolArray_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FPoolArray_Hash() { return 2584807319U; }
	DEFINE_FUNCTION(UHK_PoolingSubSystem::execReturnToPool)
	{
		P_GET_OBJECT(AActor,Z_Param_Poolable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ReturnToPool(Z_Param_Poolable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UHK_PoolingSubSystem::execSpawnFromPool)
	{
		P_GET_OBJECT(UClass,Z_Param_PoolClass);
		P_GET_STRUCT(FVector,Z_Param_Location);
		P_GET_STRUCT(FRotator,Z_Param_Rotation);
		P_GET_OBJECT_REF(AActor,Z_Param_Out_SpawnedActor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SpawnFromPool(Z_Param_PoolClass,Z_Param_Location,Z_Param_Rotation,Z_Param_Out_SpawnedActor);
		P_NATIVE_END;
	}
	void UHK_PoolingSubSystem::StaticRegisterNativesUHK_PoolingSubSystem()
	{
		UClass* Class = UHK_PoolingSubSystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ReturnToPool", &UHK_PoolingSubSystem::execReturnToPool },
			{ "SpawnFromPool", &UHK_PoolingSubSystem::execSpawnFromPool },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UHK_PoolingSubSystem_ReturnToPool_Statics
	{
		struct HK_PoolingSubSystem_eventReturnToPool_Parms
		{
			AActor* Poolable;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Poolable;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHK_PoolingSubSystem_ReturnToPool_Statics::NewProp_Poolable = { "Poolable", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HK_PoolingSubSystem_eventReturnToPool_Parms, Poolable), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHK_PoolingSubSystem_ReturnToPool_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHK_PoolingSubSystem_ReturnToPool_Statics::NewProp_Poolable,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHK_PoolingSubSystem_ReturnToPool_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pooling Subsystem" },
		{ "ModuleRelativePath", "Public/HK_PoolingSubSystem.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UHK_PoolingSubSystem_ReturnToPool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHK_PoolingSubSystem, nullptr, "ReturnToPool", nullptr, nullptr, sizeof(HK_PoolingSubSystem_eventReturnToPool_Parms), Z_Construct_UFunction_UHK_PoolingSubSystem_ReturnToPool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UHK_PoolingSubSystem_ReturnToPool_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UHK_PoolingSubSystem_ReturnToPool_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UHK_PoolingSubSystem_ReturnToPool_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UHK_PoolingSubSystem_ReturnToPool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UHK_PoolingSubSystem_ReturnToPool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UHK_PoolingSubSystem_SpawnFromPool_Statics
	{
		struct HK_PoolingSubSystem_eventSpawnFromPool_Parms
		{
			TSubclassOf<AActor>  PoolClass;
			FVector Location;
			FRotator Rotation;
			AActor* SpawnedActor;
		};
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_PoolClass;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Rotation;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpawnedActor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UHK_PoolingSubSystem_SpawnFromPool_Statics::NewProp_PoolClass = { "PoolClass", nullptr, (EPropertyFlags)0x0014000000000080, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HK_PoolingSubSystem_eventSpawnFromPool_Parms, PoolClass), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHK_PoolingSubSystem_SpawnFromPool_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HK_PoolingSubSystem_eventSpawnFromPool_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHK_PoolingSubSystem_SpawnFromPool_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HK_PoolingSubSystem_eventSpawnFromPool_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UHK_PoolingSubSystem_SpawnFromPool_Statics::NewProp_SpawnedActor = { "SpawnedActor", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HK_PoolingSubSystem_eventSpawnFromPool_Parms, SpawnedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHK_PoolingSubSystem_SpawnFromPool_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHK_PoolingSubSystem_SpawnFromPool_Statics::NewProp_PoolClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHK_PoolingSubSystem_SpawnFromPool_Statics::NewProp_Location,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHK_PoolingSubSystem_SpawnFromPool_Statics::NewProp_Rotation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHK_PoolingSubSystem_SpawnFromPool_Statics::NewProp_SpawnedActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHK_PoolingSubSystem_SpawnFromPool_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pooling Subsystem" },
		{ "DeterminesOutputType", "PoolClass" },
		{ "DynamicOutputParam", "SpawnedActor" },
		{ "ModuleRelativePath", "Public/HK_PoolingSubSystem.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UHK_PoolingSubSystem_SpawnFromPool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHK_PoolingSubSystem, nullptr, "SpawnFromPool", nullptr, nullptr, sizeof(HK_PoolingSubSystem_eventSpawnFromPool_Parms), Z_Construct_UFunction_UHK_PoolingSubSystem_SpawnFromPool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UHK_PoolingSubSystem_SpawnFromPool_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UHK_PoolingSubSystem_SpawnFromPool_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UHK_PoolingSubSystem_SpawnFromPool_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UHK_PoolingSubSystem_SpawnFromPool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UHK_PoolingSubSystem_SpawnFromPool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UHK_PoolingSubSystem_NoRegister()
	{
		return UHK_PoolingSubSystem::StaticClass();
	}
	struct Z_Construct_UClass_UHK_PoolingSubSystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ObjectPools_ValueProp;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ObjectPools_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ObjectPools_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_ObjectPools;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UHK_PoolingSubSystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_HK_PoolingSystem,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UHK_PoolingSubSystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UHK_PoolingSubSystem_ReturnToPool, "ReturnToPool" }, // 860495700
		{ &Z_Construct_UFunction_UHK_PoolingSubSystem_SpawnFromPool, "SpawnFromPool" }, // 1475513927
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHK_PoolingSubSystem_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "HK_PoolingSubSystem.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/HK_PoolingSubSystem.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHK_PoolingSubSystem_Statics::NewProp_ObjectPools_ValueProp = { "ObjectPools", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UScriptStruct_FPoolArray, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UHK_PoolingSubSystem_Statics::NewProp_ObjectPools_Key_KeyProp = { "ObjectPools_Key", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHK_PoolingSubSystem_Statics::NewProp_ObjectPools_MetaData[] = {
		{ "ModuleRelativePath", "Public/HK_PoolingSubSystem.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_UHK_PoolingSubSystem_Statics::NewProp_ObjectPools = { "ObjectPools", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UHK_PoolingSubSystem, ObjectPools), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UHK_PoolingSubSystem_Statics::NewProp_ObjectPools_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UHK_PoolingSubSystem_Statics::NewProp_ObjectPools_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHK_PoolingSubSystem_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHK_PoolingSubSystem_Statics::NewProp_ObjectPools_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHK_PoolingSubSystem_Statics::NewProp_ObjectPools_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHK_PoolingSubSystem_Statics::NewProp_ObjectPools,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UHK_PoolingSubSystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHK_PoolingSubSystem>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UHK_PoolingSubSystem_Statics::ClassParams = {
		&UHK_PoolingSubSystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UHK_PoolingSubSystem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UHK_PoolingSubSystem_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UHK_PoolingSubSystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UHK_PoolingSubSystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UHK_PoolingSubSystem()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UHK_PoolingSubSystem_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UHK_PoolingSubSystem, 3352722109);
	template<> HK_POOLINGSYSTEM_API UClass* StaticClass<UHK_PoolingSubSystem>()
	{
		return UHK_PoolingSubSystem::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UHK_PoolingSubSystem(Z_Construct_UClass_UHK_PoolingSubSystem, &UHK_PoolingSubSystem::StaticClass, TEXT("/Script/HK_PoolingSystem"), TEXT("UHK_PoolingSubSystem"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHK_PoolingSubSystem);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HK_PoolingSystem/Public/HK_Poolable.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHK_Poolable() {}
// Cross Module References
	HK_POOLINGSYSTEM_API UClass* Z_Construct_UClass_UHK_Poolable_NoRegister();
	HK_POOLINGSYSTEM_API UClass* Z_Construct_UClass_UHK_Poolable();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_HK_PoolingSystem();
// End Cross Module References
	DEFINE_FUNCTION(IHK_Poolable::execOnDespawnFromPool)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnDespawnFromPool_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IHK_Poolable::execOnSpawnFromPool)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnSpawnFromPool_Implementation();
		P_NATIVE_END;
	}
	void IHK_Poolable::OnDespawnFromPool()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnDespawnFromPool instead.");
	}
	void IHK_Poolable::OnSpawnFromPool()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnSpawnFromPool instead.");
	}
	void UHK_Poolable::StaticRegisterNativesUHK_Poolable()
	{
		UClass* Class = UHK_Poolable::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnDespawnFromPool", &IHK_Poolable::execOnDespawnFromPool },
			{ "OnSpawnFromPool", &IHK_Poolable::execOnSpawnFromPool },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UHK_Poolable_OnDespawnFromPool_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHK_Poolable_OnDespawnFromPool_Statics::Function_MetaDataParams[] = {
		{ "Category", "Poolable" },
		{ "ModuleRelativePath", "Public/HK_Poolable.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UHK_Poolable_OnDespawnFromPool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHK_Poolable, nullptr, "OnDespawnFromPool", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UHK_Poolable_OnDespawnFromPool_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UHK_Poolable_OnDespawnFromPool_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UHK_Poolable_OnDespawnFromPool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UHK_Poolable_OnDespawnFromPool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UHK_Poolable_OnSpawnFromPool_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHK_Poolable_OnSpawnFromPool_Statics::Function_MetaDataParams[] = {
		{ "Category", "Poolable" },
		{ "ModuleRelativePath", "Public/HK_Poolable.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UHK_Poolable_OnSpawnFromPool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHK_Poolable, nullptr, "OnSpawnFromPool", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UHK_Poolable_OnSpawnFromPool_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UHK_Poolable_OnSpawnFromPool_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UHK_Poolable_OnSpawnFromPool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UHK_Poolable_OnSpawnFromPool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UHK_Poolable_NoRegister()
	{
		return UHK_Poolable::StaticClass();
	}
	struct Z_Construct_UClass_UHK_Poolable_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UHK_Poolable_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_HK_PoolingSystem,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UHK_Poolable_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UHK_Poolable_OnDespawnFromPool, "OnDespawnFromPool" }, // 1642874659
		{ &Z_Construct_UFunction_UHK_Poolable_OnSpawnFromPool, "OnSpawnFromPool" }, // 1225471318
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHK_Poolable_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HK_Poolable.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UHK_Poolable_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IHK_Poolable>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UHK_Poolable_Statics::ClassParams = {
		&UHK_Poolable::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_UHK_Poolable_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UHK_Poolable_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UHK_Poolable()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UHK_Poolable_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UHK_Poolable, 2292880759);
	template<> HK_POOLINGSYSTEM_API UClass* StaticClass<UHK_Poolable>()
	{
		return UHK_Poolable::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UHK_Poolable(Z_Construct_UClass_UHK_Poolable, &UHK_Poolable::StaticClass, TEXT("/Script/HK_PoolingSystem"), TEXT("UHK_Poolable"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHK_Poolable);
	static FName NAME_UHK_Poolable_OnDespawnFromPool = FName(TEXT("OnDespawnFromPool"));
	void IHK_Poolable::Execute_OnDespawnFromPool(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UHK_Poolable::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UHK_Poolable_OnDespawnFromPool);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IHK_Poolable*)(O->GetNativeInterfaceAddress(UHK_Poolable::StaticClass())))
		{
			I->OnDespawnFromPool_Implementation();
		}
	}
	static FName NAME_UHK_Poolable_OnSpawnFromPool = FName(TEXT("OnSpawnFromPool"));
	void IHK_Poolable::Execute_OnSpawnFromPool(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UHK_Poolable::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UHK_Poolable_OnSpawnFromPool);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IHK_Poolable*)(O->GetNativeInterfaceAddress(UHK_Poolable::StaticClass())))
		{
			I->OnSpawnFromPool_Implementation();
		}
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

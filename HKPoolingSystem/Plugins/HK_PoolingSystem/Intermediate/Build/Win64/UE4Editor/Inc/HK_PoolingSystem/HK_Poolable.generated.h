// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef HK_POOLINGSYSTEM_HK_Poolable_generated_h
#error "HK_Poolable.generated.h already included, missing '#pragma once' in HK_Poolable.h"
#endif
#define HK_POOLINGSYSTEM_HK_Poolable_generated_h

#define HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_SPARSE_DATA
#define HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_RPC_WRAPPERS \
	virtual void OnDespawnFromPool_Implementation() {}; \
	virtual void OnSpawnFromPool_Implementation() {}; \
 \
	DECLARE_FUNCTION(execOnDespawnFromPool); \
	DECLARE_FUNCTION(execOnSpawnFromPool);


#define HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void OnDespawnFromPool_Implementation() {}; \
	virtual void OnSpawnFromPool_Implementation() {}; \
 \
	DECLARE_FUNCTION(execOnDespawnFromPool); \
	DECLARE_FUNCTION(execOnSpawnFromPool);


#define HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_EVENT_PARMS
#define HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_CALLBACK_WRAPPERS
#define HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	HK_POOLINGSYSTEM_API UHK_Poolable(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHK_Poolable) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(HK_POOLINGSYSTEM_API, UHK_Poolable); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHK_Poolable); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	HK_POOLINGSYSTEM_API UHK_Poolable(UHK_Poolable&&); \
	HK_POOLINGSYSTEM_API UHK_Poolable(const UHK_Poolable&); \
public:


#define HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	HK_POOLINGSYSTEM_API UHK_Poolable(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	HK_POOLINGSYSTEM_API UHK_Poolable(UHK_Poolable&&); \
	HK_POOLINGSYSTEM_API UHK_Poolable(const UHK_Poolable&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(HK_POOLINGSYSTEM_API, UHK_Poolable); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHK_Poolable); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHK_Poolable)


#define HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUHK_Poolable(); \
	friend struct Z_Construct_UClass_UHK_Poolable_Statics; \
public: \
	DECLARE_CLASS(UHK_Poolable, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/HK_PoolingSystem"), HK_POOLINGSYSTEM_API) \
	DECLARE_SERIALIZER(UHK_Poolable)


#define HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_GENERATED_UINTERFACE_BODY() \
	HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_GENERATED_UINTERFACE_BODY() \
	HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IHK_Poolable() {} \
public: \
	typedef UHK_Poolable UClassType; \
	typedef IHK_Poolable ThisClass; \
	static void Execute_OnDespawnFromPool(UObject* O); \
	static void Execute_OnSpawnFromPool(UObject* O); \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_INCLASS_IINTERFACE \
protected: \
	virtual ~IHK_Poolable() {} \
public: \
	typedef UHK_Poolable UClassType; \
	typedef IHK_Poolable ThisClass; \
	static void Execute_OnDespawnFromPool(UObject* O); \
	static void Execute_OnSpawnFromPool(UObject* O); \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_10_PROLOG \
	HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_EVENT_PARMS


#define HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_SPARSE_DATA \
	HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_RPC_WRAPPERS \
	HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_CALLBACK_WRAPPERS \
	HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_SPARSE_DATA \
	HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_CALLBACK_WRAPPERS \
	HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HK_POOLINGSYSTEM_API UClass* StaticClass<class UHK_Poolable>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HKPoolingSystem_Plugins_HK_PoolingSystem_Source_HK_PoolingSystem_Public_HK_Poolable_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

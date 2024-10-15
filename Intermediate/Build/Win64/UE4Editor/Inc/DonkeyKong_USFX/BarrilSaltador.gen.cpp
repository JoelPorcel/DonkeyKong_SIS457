// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DonkeyKong_USFX/BarrilSaltador.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBarrilSaltador() {}
// Cross Module References
	DONKEYKONG_USFX_API UClass* Z_Construct_UClass_ABarrilSaltador_NoRegister();
	DONKEYKONG_USFX_API UClass* Z_Construct_UClass_ABarrilSaltador();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_DonkeyKong_USFX();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UProjectileMovementComponent_NoRegister();
// End Cross Module References
	void ABarrilSaltador::StaticRegisterNativesABarrilSaltador()
	{
	}
	UClass* Z_Construct_UClass_ABarrilSaltador_NoRegister()
	{
		return ABarrilSaltador::StaticClass();
	}
	struct Z_Construct_UClass_ABarrilSaltador_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BarrilMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BarrilMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BarrilColision_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BarrilColision;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BarrilMovement_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BarrilMovement;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpeedIncrease_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SpeedIncrease;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MinYLimit_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MinYLimit;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxYLimit_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxYLimit;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABarrilSaltador_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_DonkeyKong_USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABarrilSaltador_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BarrilSaltador.h" },
		{ "ModuleRelativePath", "BarrilSaltador.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_BarrilMesh_MetaData[] = {
		{ "Category", "BarrilSaltador" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BarrilSaltador.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_BarrilMesh = { "BarrilMesh", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABarrilSaltador, BarrilMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_BarrilMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_BarrilMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_BarrilColision_MetaData[] = {
		{ "Category", "BarrilSaltador" },
		{ "Comment", "//Malla de colision\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BarrilSaltador.h" },
		{ "ToolTip", "Malla de colision" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_BarrilColision = { "BarrilColision", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABarrilSaltador, BarrilColision), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_BarrilColision_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_BarrilColision_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_BarrilMovement_MetaData[] = {
		{ "Category", "BarrilSaltador" },
		{ "Comment", "//Componente de velocidad\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BarrilSaltador.h" },
		{ "ToolTip", "Componente de velocidad" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_BarrilMovement = { "BarrilMovement", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABarrilSaltador, BarrilMovement), Z_Construct_UClass_UProjectileMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_BarrilMovement_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_BarrilMovement_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_SpeedIncrease_MetaData[] = {
		{ "Category", "BarrilSaltador" },
		{ "ModuleRelativePath", "BarrilSaltador.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_SpeedIncrease = { "SpeedIncrease", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABarrilSaltador, SpeedIncrease), METADATA_PARAMS(Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_SpeedIncrease_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_SpeedIncrease_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_MinYLimit_MetaData[] = {
		{ "Category", "BarrilSaltador" },
		{ "ModuleRelativePath", "BarrilSaltador.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_MinYLimit = { "MinYLimit", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABarrilSaltador, MinYLimit), METADATA_PARAMS(Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_MinYLimit_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_MinYLimit_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_MaxYLimit_MetaData[] = {
		{ "Category", "BarrilSaltador" },
		{ "ModuleRelativePath", "BarrilSaltador.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_MaxYLimit = { "MaxYLimit", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABarrilSaltador, MaxYLimit), METADATA_PARAMS(Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_MaxYLimit_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_MaxYLimit_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABarrilSaltador_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_BarrilMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_BarrilColision,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_BarrilMovement,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_SpeedIncrease,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_MinYLimit,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABarrilSaltador_Statics::NewProp_MaxYLimit,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABarrilSaltador_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABarrilSaltador>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABarrilSaltador_Statics::ClassParams = {
		&ABarrilSaltador::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ABarrilSaltador_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ABarrilSaltador_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABarrilSaltador_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABarrilSaltador_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABarrilSaltador()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABarrilSaltador_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABarrilSaltador, 2094900512);
	template<> DONKEYKONG_USFX_API UClass* StaticClass<ABarrilSaltador>()
	{
		return ABarrilSaltador::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABarrilSaltador(Z_Construct_UClass_ABarrilSaltador, &ABarrilSaltador::StaticClass, TEXT("/Script/DonkeyKong_USFX"), TEXT("ABarrilSaltador"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABarrilSaltador);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

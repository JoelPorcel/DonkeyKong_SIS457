// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DonkeyKong_USFX/PlataformaMovible.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlataformaMovible() {}
// Cross Module References
	DONKEYKONG_USFX_API UClass* Z_Construct_UClass_APlataformaMovible_NoRegister();
	DONKEYKONG_USFX_API UClass* Z_Construct_UClass_APlataformaMovible();
	DONKEYKONG_USFX_API UClass* Z_Construct_UClass_APlataforma();
	UPackage* Z_Construct_UPackage__Script_DonkeyKong_USFX();
// End Cross Module References
	void APlataformaMovible::StaticRegisterNativesAPlataformaMovible()
	{
	}
	UClass* Z_Construct_UClass_APlataformaMovible_NoRegister()
	{
		return APlataformaMovible::StaticClass();
	}
	struct Z_Construct_UClass_APlataformaMovible_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APlataformaMovible_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlataforma,
		(UObject* (*)())Z_Construct_UPackage__Script_DonkeyKong_USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlataformaMovible_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "PlataformaMovible.h" },
		{ "ModuleRelativePath", "PlataformaMovible.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APlataformaMovible_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlataformaMovible>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APlataformaMovible_Statics::ClassParams = {
		&APlataformaMovible::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APlataformaMovible_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APlataformaMovible_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APlataformaMovible()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APlataformaMovible_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APlataformaMovible, 2980345601);
	template<> DONKEYKONG_USFX_API UClass* StaticClass<APlataformaMovible>()
	{
		return APlataformaMovible::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APlataformaMovible(Z_Construct_UClass_APlataformaMovible, &APlataformaMovible::StaticClass, TEXT("/Script/DonkeyKong_USFX"), TEXT("APlataformaMovible"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlataformaMovible);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

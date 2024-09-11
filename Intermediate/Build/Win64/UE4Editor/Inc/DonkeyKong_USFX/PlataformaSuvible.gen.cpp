// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DonkeyKong_USFX/PlataformaSuvible.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlataformaSuvible() {}
// Cross Module References
	DONKEYKONG_USFX_API UClass* Z_Construct_UClass_APlataformaSuvible_NoRegister();
	DONKEYKONG_USFX_API UClass* Z_Construct_UClass_APlataformaSuvible();
	DONKEYKONG_USFX_API UClass* Z_Construct_UClass_APlataforma();
	UPackage* Z_Construct_UPackage__Script_DonkeyKong_USFX();
// End Cross Module References
	void APlataformaSuvible::StaticRegisterNativesAPlataformaSuvible()
	{
	}
	UClass* Z_Construct_UClass_APlataformaSuvible_NoRegister()
	{
		return APlataformaSuvible::StaticClass();
	}
	struct Z_Construct_UClass_APlataformaSuvible_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APlataformaSuvible_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlataforma,
		(UObject* (*)())Z_Construct_UPackage__Script_DonkeyKong_USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlataformaSuvible_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "PlataformaSuvible.h" },
		{ "ModuleRelativePath", "PlataformaSuvible.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APlataformaSuvible_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlataformaSuvible>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APlataformaSuvible_Statics::ClassParams = {
		&APlataformaSuvible::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_APlataformaSuvible_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APlataformaSuvible_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APlataformaSuvible()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APlataformaSuvible_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APlataformaSuvible, 2432442823);
	template<> DONKEYKONG_USFX_API UClass* StaticClass<APlataformaSuvible>()
	{
		return APlataformaSuvible::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APlataformaSuvible(Z_Construct_UClass_APlataformaSuvible, &APlataformaSuvible::StaticClass, TEXT("/Script/DonkeyKong_USFX"), TEXT("APlataformaSuvible"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlataformaSuvible);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

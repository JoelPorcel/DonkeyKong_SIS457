// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FabricaMuros.h"
#include "TiendaMuros.generated.h"

/**
 * 
 */
UCLASS()
class DONKEYKONG_USFX_API ATiendaMuros : public AFabricaMuros
{
	GENERATED_BODY()
	
public:

	virtual AMuro* PrepararMuro(FString _Muro, FVector _Posicion, FRotator _Rotacion) override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Muro.h"
#include "GameFramework/Actor.h"
#include "FabricaMuros.generated.h"

UCLASS()
class DONKEYKONG_USFX_API AFabricaMuros : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabricaMuros();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Crea la Poción y la devuelve. Es puramente virtual, por lo que no necesita una implementación en esta clase
	virtual AMuro* PrepararMuro(FString _Muro, FVector _Posicion, FRotator _Rotacion) PURE_VIRTUAL(AFafricaMuros::PrepararMuro, return nullptr;);


	//Pide, prepara y devuelve una Poción de una Categoría específica
	AMuro* EncargarMuro(FString _Categoria, FVector _Posicion, FRotator _Rotacion);
};

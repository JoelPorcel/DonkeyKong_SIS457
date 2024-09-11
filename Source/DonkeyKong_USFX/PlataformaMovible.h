// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaMovible.generated.h"

/**
 * 
 */
UCLASS()
class DONKEYKONG_USFX_API APlataformaMovible : public APlataforma
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	FVector posicionInicial;
	FVector posicionActual;
	FVector posicionFinal;
	float incrementoY;
	bool moverse;
	float t;
public:
	void movimientoY();
};

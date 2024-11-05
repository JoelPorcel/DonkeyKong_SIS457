// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Decorador.h"
#include "DecoradorCorredor.generated.h"

UCLASS()
class DONKEYKONG_USFX_API ADecoradorCorredor : public ADecorador
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADecoradorCorredor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float corredor() override;
	float saltador() override { return 2; };
};

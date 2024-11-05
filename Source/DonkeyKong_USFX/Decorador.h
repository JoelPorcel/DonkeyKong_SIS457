// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "IJugador.h"
#include "Decorador.generated.h"

UCLASS()
class DONKEYKONG_USFX_API ADecorador : public APawn, public IIJugador
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADecorador();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	IIJugador* Jugador;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void setJugador(APawn* jugador);
	float corredor() override;
	float saltador() override;

};

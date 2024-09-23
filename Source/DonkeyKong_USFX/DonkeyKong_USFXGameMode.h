// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DonkeyKong_USFXGameMode.generated.h"

UCLASS(minimalapi)
class ADonkeyKong_USFXGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADonkeyKong_USFXGameMode();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	TMap<int, AActor*> Plataformas;
	TArray<AActor*> Barriles;
	TArray<AActor*> Parkour;
	TArray<AActor*> Enemigos;
	FVector Posicion;
	FRotator Rotacion;
	FVector Spawn;
	FVector Aparicion;
	float signo;
	float tiempo;
	float constant_z;
	int random;
	int desicion;
	int componentes;
	int movimiento;
	int ID;
	AActor* destruir = nullptr;

	//enemigos
	FVector enemigo;
	FVector enemigo_;
	FVector Pu;
	int enemigosCant;
	float z;
	float y;
	int control;
};




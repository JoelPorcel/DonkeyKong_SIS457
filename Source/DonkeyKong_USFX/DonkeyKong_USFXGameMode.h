// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Plataforma.h"
#include "IJugador.h"
#include "DonkeyKong_USFXGameMode.generated.h"

class AMuro;

UCLASS(minimalapi)
class ADonkeyKong_USFXGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADonkeyKong_USFXGameMode();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	class AMono* mono;

private:
	//El Actor Constructor
	UPROPERTY(VisibleAnywhere, Category = "GameModeBase")
	class ABuilderTipoA* Constructor;
	UPROPERTY(VisibleAnywhere, Category = "GameModeBase")
	class ABuilderTipoB* Constructor2;


	//El Actor Ingeniero
	UPROPERTY(VisibleAnywhere, Category = "GameModeBase")
	class AArquitecto* Ingeniero;

public:
	virtual void Tick(float DeltaTime) override;

	TMap<int, AActor*> Plataformas;
	TArray<AActor*> Barriles;
	TArray<AActor*> Parkour;
	TArray<AMuro*> Muros;
	//TArray<AMono*> Enemigos; // mono
	FVector Posicion;
	FRotator Rotacion;
	FVector Spawn;
	FVector Aparicion;
	float signo;
	float tiempo;
	float constant_z;
	int random;
	int ID;
	void PlataformasMovimiento();
	int limitePlataformas;

	//enemigos
	FVector enemigoAleatorio;
	int enemigosCant;
	void GenerarEnemigos();

protected:
	TArray<TSubclassOf<class AMuro>> Paredes;

	float Timer;

	void GenerarParedesAleatorias();

	int IndiceAleatorio;

	TSubclassOf<class AMuro> ParedesAleatorias;
	FVector UbicacionAleatoria;
	int PlataformaAleatoria;
	int CantidadMuros;



	float segundos;
	AActor* Escenario;


	//para los enemigos
	TMap<int, APlataforma*> PosicionMapa;

	//para el decorador
	IIJugador* Personaje;
};




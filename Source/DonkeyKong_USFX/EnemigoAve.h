// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigos.h"
#include "EnemigoAve.generated.h"

UCLASS()
class DONKEYKONG_USFX_API AEnemigoAve : public AEnemigos
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemigoAve();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void atacar() override;
	void vigilar() override;
	void eliminar() override;
	void spawn(TMap<int, APlataforma*> _Posicion) override;
	void RealizarTareas(FString& _Tareas, TMap<int, APlataforma*> _Posicion) override;
};

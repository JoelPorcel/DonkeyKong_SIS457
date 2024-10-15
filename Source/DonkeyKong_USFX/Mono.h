// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mono.generated.h"

class AProyectil;

UCLASS()
class DONKEYKONG_USFX_API AMono : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMono();

	UPROPERTY()
	AMono* Instancia;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	TSubclassOf<AProyectil> ProjectileClass;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* monoMesh;

	void SpawnProyectil();
	float intervalo;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BarrilSaltador.generated.h"

UCLASS()
class DONKEYKONG_USFX_API ABarrilSaltador : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrilSaltador();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* BarrilMesh;

	//Malla de colision
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USphereComponent* BarrilColision;

	//Componente de velocidad
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UProjectileMovementComponent* BarrilMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float SpeedIncrease;

	virtual void NotifyHit(
		class UPrimitiveComponent* MyComp,
		class AActor* Other,
		class UPrimitiveComponent* OtherComp,
		bool bSelfMoved,
		FVector HitLocation,
		FVector HitNormal,
		FVector NormalImpulse,
		const FHitResult& Hit
	) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MinYLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxYLimit;

	//limites de movimiento
	FVector ubicacionActual;
	FVector velocidadActual;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Barril.generated.h"

UCLASS()
class DONKEYKONG_USFX_API ABarril : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ABarril();
	float DireccionMovimiento;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	//class UComponenteExtra* Componenteextra;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* BarrilMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USphereComponent* BarrilColision;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UProjectileMovementComponent* BarrilMovement;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	float LimiteMinY;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	float LimiteMaxY;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	float CoordenadaFijaX;

	UFUNCTION()
	virtual void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	void destruirBarril();

	FTimerHandle Timer;

	float RotacionRate;
};

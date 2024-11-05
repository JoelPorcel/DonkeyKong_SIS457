// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Barril.h"
#include "BarrilExplosivo.generated.h"

UCLASS()
class DONKEYKONG_USFX_API ABarrilExplosivo : public ABarril
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrilExplosivo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) override;

	class UParticleSystemComponent* ParticleSystem;

	int unaExplosion;
};

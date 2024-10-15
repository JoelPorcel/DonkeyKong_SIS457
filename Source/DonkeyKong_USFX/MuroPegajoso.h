// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Muro.h"
#include "MuroPegajoso.generated.h"

UCLASS()
class DONKEYKONG_USFX_API AMuroPegajoso : public AMuro
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMuroPegajoso();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class UParticleSystemComponent* ParticleSystem;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) override;

	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	void Mensaje() override;

	void armarMuro() override;
};

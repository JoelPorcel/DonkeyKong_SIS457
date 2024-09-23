// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Muro.h"
#include "MuroCongelado.generated.h"

/**
 * 
 */
UCLASS()
class DONKEYKONG_USFX_API AMuroCongelado : public AMuro
{
	GENERATED_BODY()
	
public:
	AMuroCongelado();
	class UParticleSystemComponent* ParticleSystem;
	class UCharacterMovementComponent* MovementComponent;
	UFUNCTION()
	virtual void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
};

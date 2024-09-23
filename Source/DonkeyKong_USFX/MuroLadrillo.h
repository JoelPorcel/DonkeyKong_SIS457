// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Muro.h"
#include "MuroLadrillo.generated.h"

/**
 * 
 */
UCLASS()
class DONKEYKONG_USFX_API AMuroLadrillo : public AMuro
{
	GENERATED_BODY()
	
	AMuroLadrillo();
	class UParticleSystemComponent* ParticleSystem;
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
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DonkeyKong_USFXCharacter.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Muro.generated.h"


UCLASS()
class DONKEYKONG_USFX_API AMuro : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AMuro();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	class UStaticMeshComponent* MuroMesh;
	class UBoxComponent* MuroColision;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

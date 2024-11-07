// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IProyectil.h"
#include "AdaptadorProyectil.generated.h"

UCLASS()
class DONKEYKONG_USFX_API AAdaptadorProyectil : public AActor, public IIProyectil
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAdaptadorProyectil();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void LanzarProyectil() override;

private:
	class AProyectil* Proyectil;
	class ADonkeyKong_USFXCharacter* Mario;

};

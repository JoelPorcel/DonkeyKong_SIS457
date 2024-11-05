// Fill out your copyright notice in the Description page of Project Settings.


#include "DecoradorCorredor.h"
#include "DonkeyKong_USFXCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ADecoradorCorredor::ADecoradorCorredor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADecoradorCorredor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADecoradorCorredor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ADecoradorCorredor::corredor()
{
	ADonkeyKong_USFXCharacter* personaje = Cast<ADonkeyKong_USFXCharacter>(Jugador);
	if (personaje)
	{
		return personaje->GetCharacterMovement()->MaxWalkSpeed = Super::corredor()+2000; // Modifica directamente
	}
	return 0;
}


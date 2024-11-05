// Fill out your copyright notice in the Description page of Project Settings.


#include "DecoradorSaltador.h"
#include "DonkeyKong_USFXCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ADecoradorSaltador::ADecoradorSaltador()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADecoradorSaltador::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADecoradorSaltador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADecoradorSaltador::setJugador(APawn* jugador)
{
	Jugador = Cast<IIJugador>(jugador);
}

float ADecoradorSaltador::saltador()
{
	ADonkeyKong_USFXCharacter* personaje = Cast<ADonkeyKong_USFXCharacter>(Jugador);
	if (personaje)
	{
		return personaje->GetCharacterMovement()->JumpZVelocity = Super::saltador() + 2000; // Modifica directamente
	}
	return 0;
}


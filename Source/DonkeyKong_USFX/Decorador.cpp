// Fill out your copyright notice in the Description page of Project Settings.


#include "Decorador.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DonkeyKong_USFXCharacter.h"

// Sets default values
ADecorador::ADecorador()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADecorador::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADecorador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADecorador::setJugador(APawn* jugador)
{
	Jugador = Cast<IIJugador>(jugador);
}

void ADecorador::setCorrer(float _correr)
{
	Jugador->setCorrer(_correr);
}

void ADecorador::setSaltar(float _salto)
{
	Jugador->setSaltar(_salto);
}

float ADecorador::getCorrer()
{
	return Jugador->getCorrer();
}

float ADecorador::getSaltar()
{
	return Jugador->getSaltar();
}



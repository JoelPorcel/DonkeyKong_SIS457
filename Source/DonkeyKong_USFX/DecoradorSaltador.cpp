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

void ADecoradorSaltador::setCorrer(float _correr)
{
	float correrA = getCorrer();
	Jugador->setCorrer(correrA + _correr );
}

void ADecoradorSaltador::setSaltar(float _salto)
{
	float saltar = getSaltar();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Velocidad Actual en el decorador       : %f"), saltar));
	Jugador->setSaltar(saltar + _salto);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Velocidad Actual en el decorador       : %f"), Jugador->getSaltar()));
}

float ADecoradorSaltador::getCorrer()
{
	return Super::getCorrer();
}

float ADecoradorSaltador::getSaltar()
{
	return Super::getSaltar();
}

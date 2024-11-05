// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoPuercoEspin.h"

// Sets default values
AEnemigoPuercoEspin::AEnemigoPuercoEspin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemigoPuercoEspin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemigoPuercoEspin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemigoPuercoEspin::atacar()
{
}

void AEnemigoPuercoEspin::vigilar()
{
}

void AEnemigoPuercoEspin::eliminar()
{
}

void AEnemigoPuercoEspin::spawn(TMap<int, APlataforma*> _Posicion)
{
}


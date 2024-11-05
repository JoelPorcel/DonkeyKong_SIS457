// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoLobo.h"

// Sets default values
AEnemigoLobo::AEnemigoLobo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemigoLobo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemigoLobo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemigoLobo::atacar()
{
}

void AEnemigoLobo::vigilar()
{
}

void AEnemigoLobo::eliminar()
{
}

void AEnemigoLobo::spawn(TMap<int, APlataforma*> _Posicion)
{
}

void AEnemigoLobo::RealizarTareas(FString& _Tareas, TMap<int, APlataforma*> _Posicion)
{
}



// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaSuvible.h"

void APlataformaSuvible::BeginPlay()
{
	Super::BeginPlay();
	posicionInicial = GetActorLocation();
	posicionActual = posicionInicial;
	posicionFinal = posicionActual + FVector(0.0f, 0.0f, -300.0f);
	incrementoZ = 2.0f;
	moverse = true;
	t = 0.0f;
}

void APlataformaSuvible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	movimientoZ();
}

void APlataformaSuvible::movimientoZ()
{
	if (moverse)
	{
		if (posicionActual.Z > posicionFinal.Z) posicionActual.Z -= incrementoZ;
		else moverse = false;
	}
	else
	{
		if (posicionActual.Z < posicionInicial.Z) posicionActual.Z += incrementoZ;
		else moverse = true;
	}

	SetActorLocation(posicionActual);
}
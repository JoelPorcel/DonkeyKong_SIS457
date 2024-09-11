// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaMovible.h"

void APlataformaMovible::BeginPlay()
{
	Super::BeginPlay();
	posicionInicial = GetActorLocation();
	posicionActual = posicionInicial;
	posicionFinal = posicionActual + FVector(0.0f, -840.0f, 0.0f);
	incrementoY = 2.0f;
	moverse = true;
	t = 0.0f;
}

void APlataformaMovible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	t += DeltaTime;
	if (t >= 10.0f) {
		movimientoY();
	}
}

void APlataformaMovible::movimientoY()
{
	if (moverse)
	{
		if (posicionActual.Y > posicionFinal.Y) posicionActual.Y -= incrementoY;
		else moverse = false;
	}
	else
	{
		if (posicionActual.Y < posicionInicial.Y) posicionActual.Y += incrementoY;
		else moverse = true;
	}

	SetActorLocation(posicionActual);
}
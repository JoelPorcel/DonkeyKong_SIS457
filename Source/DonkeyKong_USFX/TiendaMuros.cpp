// Fill out your copyright notice in the Description page of Project Settings.


#include "TiendaMuros.h"
#include "MuroCongelado.h"
#include "MuroElectrico.h"
#include "MuroEspinoso.h"
#include "MuroLadrillo.h"
#include "MuroPegajoso.h"

AMuro* ATiendaMuros::PrepararMuro(FString _Muro, FVector _Posicion, FRotator _Rotacion = FRotator::ZeroRotator)
{
    if (_Muro.Equals("Muro congelado")) {
		return GetWorld()->SpawnActor<AMuroCongelado>(AMuroCongelado::StaticClass(), _Posicion, _Rotacion);
	}
	else if (_Muro.Equals("Muro electrico")) {
		return GetWorld()->SpawnActor<AMuroElectrico>(AMuroElectrico::StaticClass(), _Posicion, _Rotacion);
	}
	else if (_Muro.Equals("Muro espinoso")) {
		return GetWorld()->SpawnActor<AMuroEspinoso>(AMuroEspinoso::StaticClass(), _Posicion, _Rotacion);
	}
	else if (_Muro.Equals("Muro ladrillo")) {
		return GetWorld()->SpawnActor<AMuroLadrillo>(AMuroLadrillo::StaticClass(), _Posicion, _Rotacion);
	}
	else if (_Muro.Equals("Muro pegajoso")) {
		return GetWorld()->SpawnActor<AMuroPegajoso>(AMuroPegajoso::StaticClass(), _Posicion, _Rotacion);
	}
	else {
		return nullptr;
	}
}

// Fill out your copyright notice in the Description page of Project Settings.  
 
 
#include "FabricaMuros.h"  
 
// Sets default values  
AFabricaMuros::AFabricaMuros()  
{  
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.  
	PrimaryActorTick.bCanEverTick = true;  
 
}  
 
// Called when the game starts or when spawned  
void AFabricaMuros::BeginPlay()  
{  
	Super::BeginPlay();  
  
}  
 
// Called every frame  
void AFabricaMuros::Tick(float DeltaTime)  
{  
	Super::Tick(DeltaTime);  
}  

AMuro* AFabricaMuros::EncargarMuro(FString _Categoria, FVector _Posicion, FRotator _Rotacion)
{
	AMuro* Muro = PrepararMuro(_Categoria, _Posicion, _Rotacion);
	GEngine->AddOnScreenDebugMessage(-1, 7.f, FColor::Yellow, FString::Printf(TEXT("Armando Muro %s"), *Muro->ObtenerNombreDelMuro()));
	Muro->armarMuro();
	return Muro;
}
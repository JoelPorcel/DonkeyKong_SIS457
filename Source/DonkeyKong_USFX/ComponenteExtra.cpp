// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponenteExtra.h"
#include "Engine/Engine.h"

// Sets default values for this component's properties
UComponenteExtra::UComponenteExtra()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UComponenteExtra::BeginPlay()
{
	Super::BeginPlay();
	// ...

}


// Called every frame
void UComponenteExtra::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UComponenteExtra::Desaparecer(AActor* actor)
{
	actor->SetActorHiddenInGame(true);
	//actor->SetActorEnableCollision(false);  //coliciones desactivadas(true) o ectivadas(false)
	//actor->SetActorTickEnabled(false);
}

void UComponenteExtra::Aparecer(AActor* actor)
{
	actor->SetActorHiddenInGame(false);
	//actor->SetActorEnableCollision(true);  //coliciones desactivadas(true) o ectivadas(false)
	//actor->SetActorTickEnabled(true);
}

void UComponenteExtra::Subir(AActor* actor)
{
	FVector PosicionActual = actor->GetActorLocation();
	PosicionActual.Z += 200.0f;
	actor->SetActorLocation(PosicionActual);
}

void UComponenteExtra::Bajar(AActor* actor)
{
	FVector PosicionActual = actor->GetActorLocation();
	PosicionActual.Z -= 200.0f;
	actor->SetActorLocation(PosicionActual);
}

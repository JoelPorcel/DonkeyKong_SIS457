// Fill out your copyright notice in the Description page of Project Settings.


#include "AdaptadorProyectil.h"
#include "Proyectil.h"
#include "Kismet/GameplayStatics.h"
#include "DonkeyKong_USFXCharacter.h"

// Sets default values
AAdaptadorProyectil::AAdaptadorProyectil()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAdaptadorProyectil::BeginPlay()
{
	Super::BeginPlay();
	Proyectil = GetWorld()->SpawnActor<AProyectil>(AProyectil::StaticClass());
	Mario = Cast<ADonkeyKong_USFXCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

// Called every frame
void AAdaptadorProyectil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAdaptadorProyectil::LanzarProyectil()
{
	if (Mario) {
		FVector SpawnLocation = Mario->GetActorLocation() + Mario->GetActorForwardVector() * 100;
		FRotator SpawnRotation = Mario->GetActorRotation();
		FVector ForwardDirection = Mario->GetActorForwardVector();
		if (ForwardDirection.Y >= 0.99 && Proyectil) {
			Proyectil->locationProyectil(SpawnLocation, SpawnRotation, ForwardDirection);
		}
		else if (ForwardDirection.Y <= -0.99 && Proyectil) {
			Proyectil->locationProyectil(SpawnLocation, SpawnRotation, ForwardDirection);
		}
	}
}

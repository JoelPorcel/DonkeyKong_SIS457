// Fill out your copyright notice in the Description page of Project Settings.


#include "BarrilComun.h"
#include "plataforma.h"

// Sets default values
ABarrilComun::ABarrilComun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABarrilComun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABarrilComun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABarrilComun::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(!OtherActor->IsA(APlataforma::StaticClass())) DireccionMovimiento *= -1;
}


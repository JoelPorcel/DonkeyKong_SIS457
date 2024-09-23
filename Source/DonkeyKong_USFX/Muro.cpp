// Fill out your copyright notice in the Description page of Project Settings.


#include "Muro.h"
#include "DonkeyKong_USFXCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "DonkeyKong_USFXCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMuro::AMuro()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//establece el componenete raiz de la malla
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Muro(TEXT("StaticMesh'/Game/StarterContent/Architecture/Wall_400x300.Wall_400x300'"));
	// Crear el componente de malla est?tica
	//Mallas de la clase
	MuroMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla_MuroElectrico"));
	MuroMesh->SetStaticMesh(Muro.Object);
	MuroMesh->SetRelativeScale3D(FVector(0.5, 0.5, 1.5));
	MuroMesh->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
	RootComponent = MuroMesh;

	MuroColision = CreateDefaultSubobject<UBoxComponent>(TEXT("Barril_Colision"));
	MuroColision->SetBoxExtent(FVector(200.0f, 50.0f, 150.0f));
	MuroColision->SetRelativeLocation(FVector(250.0f, 0.0f, 120.0f));
	MuroColision->SetVisibility(true);
	MuroColision->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AMuro::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMuro::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




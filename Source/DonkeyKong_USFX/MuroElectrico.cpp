// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroElectrico.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "BarrilExplosivo.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

AMuroElectrico::AMuroElectrico()
{
	PrimaryActorTick.bCanEverTick = true;
	MuroMesh->SetMaterial(0, LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse'")));

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem1"));
	ParticleSystem->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Sparks.P_Sparks'"));
	if (ParticleSystemAsset.Succeeded())
	{
		ParticleSystem->SetTemplate(ParticleSystemAsset.Object);
	}
	ParticleSystem->SetWorldScale3D(FVector(3.0f, 3.0f, 3.0f));
	MuroMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	MuroMesh->SetCollisionResponseToAllChannels(ECR_Overlap);

	NombreDelMuro = "Muro Electrico";
}

void AMuroElectrico::BeginPlay()
{
	Super::BeginPlay();
}

void AMuroElectrico::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Muro creado"));
}


void AMuroElectrico::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Mensaje();
	//if (OtherActor && OtherActor != this)  // Aseg?rate de no destruir el propio muro
	//{
	//	OtherActor->Destroy();
	//}
	Barril = Cast<ABarrilExplosivo>(OtherActor);
	if (Barril) {
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Superposicion con Barril!"));
		Barril->BarrilColision->SetSphereRadius(700.0f);
		Barril->BarrilMesh->SetVisibility(false);
		Barril->BarrilMovement->MaxSpeed = 0.0f;
		Barril->BarrilMesh->SetCollisionResponseToAllChannels(ECR_Overlap);
		GetWorld()->GetTimerManager().SetTimer(Timer, this, &AMuro::destruirBarril, 3.F, false);
	}
}

void AMuroElectrico::Mensaje()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, FString::Printf(TEXT("Esta es una pared electrica")));
}

void AMuroElectrico::armarMuro()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Muro electrico armado"));
}

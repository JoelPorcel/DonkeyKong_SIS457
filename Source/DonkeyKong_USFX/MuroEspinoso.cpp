// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroEspinoso.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BarrilExplosivo.h"
#include "Components/SphereComponent.h"
#include "DonkeyKong_USFXCharacter.h"

// Sets default values
AMuroEspinoso::AMuroEspinoso()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    MuroMesh->SetMaterial(0, LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'")));

    // Crear el sistema de part?culas
    ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
    ParticleSystem->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Steam_Lit.P_Steam_Lit'"));
    if (ParticleSystemAsset.Succeeded())
    {
        ParticleSystem->SetTemplate(ParticleSystemAsset.Object);
    }

	NombreDelMuro = "Muro Espinoso";
}

// Called when the game starts or when spawned
void AMuroEspinoso::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void AMuroEspinoso::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMuroEspinoso::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    Super::OnOverlapBegin(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
    //Mensaje();
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

void AMuroEspinoso::Mensaje()
{
    GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, FString::Printf(TEXT("Esta es una pared con espinas")));
}

void AMuroEspinoso::armarMuro()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Muro con espinas creado"));
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroCongelado.h"
#include "DonkeyKong_USFXCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BarrilExplosivo.h"
#include "Components/SphereComponent.h"

AMuroCongelado::AMuroCongelado()
{
    PrimaryActorTick.bCanEverTick = true;
    MuroMesh->SetMaterial(0, LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Basic_Floor.M_Basic_Floor'")));

    // Crear el sistema de part?culas
    ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
    ParticleSystem->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Steam_Lit.P_Steam_Lit'"));
    if (ParticleSystemAsset.Succeeded())
    {
        ParticleSystem->SetTemplate(ParticleSystemAsset.Object);
    }
    ParticleSystem->SetWorldScale3D(FVector(3.0f, 3.0f, 3.0f));
    MuroMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
    MuroMesh->SetCollisionResponseToAllChannels(ECR_Overlap);

	NombreDelMuro = "Muro Congelado";
}

void AMuroCongelado::BeginPlay()
{
    Super::BeginPlay();
}

void AMuroCongelado::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}


void AMuroCongelado::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    Super::OnOverlapBegin(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
    //Mensaje();
    ADonkeyKong_USFXCharacter* DonkeyKongCharacter = Cast<ADonkeyKong_USFXCharacter>(OtherActor);
    Barril = Cast<ABarrilExplosivo>(OtherActor);
    if (Barril) {
        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Superposicion con Barril!"));
        Barril->BarrilColision->SetSphereRadius(1300.0f);
		Barril->BarrilMesh->SetVisibility(false);
		Barril->BarrilMovement->MaxSpeed = 0.0f;
        Barril->BarrilMesh->SetCollisionResponseToAllChannels(ECR_Overlap);
        GetWorld()->GetTimerManager().SetTimer(Timer, this, &AMuro::destruirBarril, 3.F, false);
    }
    if (DonkeyKongCharacter)
    {
        // El cast fue exitoso, hacer algo con el personaje
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Superposicion con Donkey Kong Character!"));

        // Puedes acceder a las funciones o variables del personaje ahora
        DonkeyKongCharacter->GetCharacterMovement()->MaxWalkSpeed = 0.0f;
		DonkeyKongCharacter->SetPuntaje(DonkeyKongCharacter->GetPuntaje() - 10);
    }
}

void AMuroCongelado::Mensaje()
{
    GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, FString::Printf(TEXT("Esta es una pared congelada")));
}

void AMuroCongelado::armarMuro()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, FString::Printf(TEXT("Armando muro congelado")));
}

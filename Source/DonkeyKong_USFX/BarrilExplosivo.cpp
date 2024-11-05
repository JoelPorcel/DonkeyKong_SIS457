// Fill out your copyright notice in the Description page of Project Settings.


#include "BarrilExplosivo.h"
#include "Components/SphereComponent.h"
#include "ComponenteExtra.h"
#include "DonkeyKong_USFXCharacter.h"
#include "Particles/ParticleSystemComponent.h"
#include "Muro.h"

// Sets default values
ABarrilExplosivo::ABarrilExplosivo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    BarrilMesh->SetMaterial(0, LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse'")));

    ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
    ParticleSystem->SetupAttachment(RootComponent);
    static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));

    if (ParticleSystemAsset.Succeeded())
    {
        if (ParticleSystem)
        {
            ParticleSystem->SetTemplate(ParticleSystemAsset.Object);
        }
    }
    ParticleSystem->bAutoActivate = false;
	ParticleSystem->SetWorldScale3D(FVector(9.0f));

    unaExplosion = 0;
}

// Called when the game starts or when spawned
void ABarrilExplosivo::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABarrilExplosivo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABarrilExplosivo::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    ADonkeyKong_USFXCharacter* DonkeyKongCharacter = Cast<ADonkeyKong_USFXCharacter>(OtherActor);
    if (DonkeyKongCharacter) {
        if (DonkeyKongCharacter->GetVidas() >= 1) {
            DonkeyKongCharacter->SetVidas(DonkeyKongCharacter->GetVidas() - 1);
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Perdiste una vida, vidas restantes: %d"), DonkeyKongCharacter->GetVidas()));
        }
        if (DonkeyKongCharacter->GetPuntaje() > 0) {
            DonkeyKongCharacter->SetPuntaje(DonkeyKongCharacter->GetPuntaje() - 50.0f);
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Puntaje actual: %.1f"), DonkeyKongCharacter->GetPuntaje()));
        }
        BarrilColision->SetSphereRadius(1000.0f);
        BarrilMesh->SetVisibility(false);
        BarrilMovement->MaxSpeed = 0.0f;
        BarrilMesh->SetCollisionResponseToAllChannels(ECR_Overlap);
        // sistema de explosion
        if (this) {
            GetWorld()->GetTimerManager().SetTimer(Timer, this, &ABarril::destruirBarril, 3.F, false);
        }
    }
    if (OtherActor != this && (OtherActor->IsA(AMuro::StaticClass()) || OtherActor->IsA(ADonkeyKong_USFXCharacter::StaticClass())) && unaExplosion == 0) {
		unaExplosion = 1;
        ParticleSystem->SetWorldLocation(GetActorLocation());  // Ubicar las partículas
        ParticleSystem->Activate(true);  // Activar las partícula
    }
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroLadrillo.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "ComponenteExtra.h"
#include "BarrilExplosivo.h"
#include "Components/SphereComponent.h"
#include "DonkeyKong_USFXCharacter.h"

AMuroLadrillo::AMuroLadrillo()
{
	PrimaryActorTick.bCanEverTick = true;
	MuroMesh->SetMaterial(0, LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Brick_Clay_New.M_Brick_Clay_New'")));

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ParticleSystem->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	if (ParticleSystemAsset.Succeeded())
	{
		ParticleSystem->SetTemplate(ParticleSystemAsset.Object);
	}

	NombreDelMuro = "Muro de Ladrillo";
}

void AMuroLadrillo::BeginPlay()
{
	Super::BeginPlay();

}

void AMuroLadrillo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//cambio += DeltaTime;
	//if (cambio > 5 && ContadorCambio == 0) {
	//	Componenteextra->Subir(this);
	//	ContadorCambio += 1;
	//}
	//else if (cambio > 10) {
	//	Componenteextra->Bajar(this);
	//	cambio = 0;
	//	ContadorCambio = 0;
	//}
}


void AMuroLadrillo::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
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
	ADonkeyKong_USFXCharacter* DonkeyKongCharacter = Cast<ADonkeyKong_USFXCharacter>(OtherActor);
	if (DonkeyKongCharacter)
	{
		DonkeyKongCharacter->SetPuntaje(DonkeyKongCharacter->GetPuntaje() - 10);
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Perdiste puntos"));
	}
}

void AMuroLadrillo::Mensaje()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, FString::Printf(TEXT("Esta es una pared de ladrillo")));
}

void AMuroLadrillo::armarMuro()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Muro de ladrillo creado"));
}

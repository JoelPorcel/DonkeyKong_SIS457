// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroPegajoso.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "DonkeyKong_USFXCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ComponenteExtra.h"
#include "BarrilExplosivo.h"
#include "Components/SphereComponent.h"
#include "DonkeyKong_USFXCharacter.h"

// Sets default values
AMuroPegajoso::AMuroPegajoso()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MuroMesh->SetMaterial(0, LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Ground_Grass.M_Ground_Grass'")));

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ParticleSystem->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	if (ParticleSystemAsset.Succeeded())
	{
		ParticleSystem->SetTemplate(ParticleSystemAsset.Object);
	}
	MuroMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	MuroMesh->SetCollisionResponseToAllChannels(ECR_Overlap);

	NombreDelMuro = "Muro Pegajoso";
}

// Called when the game starts or when spawned
void AMuroPegajoso::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMuroPegajoso::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	cambio += DeltaTime;
	if (cambio > 5 && ContadorCambio == 0) {
		Componenteextra->Desaparecer(this);
		ContadorCambio += 1;
	}
	else if (cambio > 10) {
		Componenteextra->Aparecer(this);
		cambio = 0;
		ContadorCambio = 0;
	}
}

void AMuroPegajoso::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	//Mensaje();
	ADonkeyKong_USFXCharacter* DonkeyKongCharacter = Cast<ADonkeyKong_USFXCharacter>(OtherActor);
	if (DonkeyKongCharacter)
	{
		// Puedes acceder a las funciones o variables del personaje ahora
		DonkeyKongCharacter->GetCharacterMovement()->MaxWalkSpeed = 60.0f;
		DonkeyKongCharacter->SetPuntaje(DonkeyKongCharacter->GetPuntaje() - 10);
	}
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

void AMuroPegajoso::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex);

	ADonkeyKong_USFXCharacter* DonkeyKongCharacter = Cast<ADonkeyKong_USFXCharacter>(OtherActor);
	if (DonkeyKongCharacter)
	{
		// Puedes acceder a las funciones o variables del personaje ahora
		DonkeyKongCharacter->GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	}
}


void AMuroPegajoso::Mensaje()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Muro Pegajoso"));
}

void AMuroPegajoso::armarMuro()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Muro Pegajoso creado"));
}


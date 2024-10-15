// Fill out your copyright notice in the Description page of Project Settings.


#include "BarrilSaltador.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABarrilSaltador::ABarrilSaltador()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//establece el componenete raiz de la malla
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Barril(TEXT("StaticMesh'/Game/Geometry/Meshes/BarrilSaltador.BarrilSaltador'"));
	// Crear el componente de malla est?tica
	//Mallas de la clase
	BarrilMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla_Barrilmovimiento"));
	BarrilMesh->SetStaticMesh(Barril.Object);
	BarrilMesh->SetRelativeScale3D(FVector(1.5, 1.5, 2.0));
	BarrilMesh->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
	SetRootComponent(BarrilMesh);

	//Malla de colision
	BarrilColision = CreateDefaultSubobject<USphereComponent>(TEXT("Barril_Colision"));
	BarrilColision->SetSphereRadius(35.0f);
	BarrilColision->SetRelativeLocation(FVector(0.0f, 0.0f, 30.0f));
	BarrilColision->SetVisibility(true);
	BarrilColision->SetupAttachment(GetRootComponent());

	//Movimiento
	BarrilMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Barril_Movimiento"));
	BarrilMovement->UpdatedComponent = BarrilMesh;
	BarrilMovement->InitialSpeed = 250.0f;
	BarrilMovement->MaxSpeed = 1250.0f;
	BarrilMovement->bRotationFollowsVelocity = false;
	BarrilMovement->bShouldBounce = true;
	BarrilMovement->Bounciness = 0.7f;
	BarrilMovement->Friction = 0.1;

	//incremento de velocidad
	SpeedIncrease = 250.f;

	//Limites
	MinYLimit = 2100.0f;
	MaxYLimit = -1600.0f;
}

// Called when the game starts or when spawned
void ABarrilSaltador::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABarrilSaltador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ubicacionActual = GetActorLocation();
	if (ubicacionActual.Y >= MinYLimit)
	{
		BarrilMovement->Velocity = FVector(-velocidadActual.X, -115.0f, -115.0f);
	}
	else if (ubicacionActual.Y <= MaxYLimit)
	{
		BarrilMovement->Velocity = FVector(velocidadActual.X, 115.0f, 115.0f);
	}
	ubicacionActual.X = 1280.0f;
	if (BarrilMesh) {
		BarrilMesh->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
	}
}

void ABarrilSaltador::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	FVector CurrentVelocity = BarrilMovement->Velocity;
	FVector NewVelocity = CurrentVelocity.GetSafeNormal() * (CurrentVelocity.Size() + this->SpeedIncrease);

	if (NewVelocity.Size() <= BarrilMovement->MaxSpeed) {
		BarrilMovement->Velocity = NewVelocity;
	}
}
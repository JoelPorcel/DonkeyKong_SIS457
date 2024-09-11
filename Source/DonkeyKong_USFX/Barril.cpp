// Fill out your copyright notice in the Description page of Project Settings.


#include "Barril.h"

// Sets default values
ABarril::ABarril()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//establece el componenete raiz de la malla
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Barril(TEXT("StaticMesh'/Game/Geometry/Meshes/Barril.Barril'"));
	// Crear el componente de malla estática
	//Mallas de la clase
	BarrilMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla_Barril"));
	BarrilMesh->SetStaticMesh(Barril.Object);
	BarrilMesh->SetRelativeScale3D(FVector(1.5, 1.5, 2.0));
	BarrilMesh->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
	BarrilMesh->SetSimulatePhysics(true);
	BarrilMesh->SetMobility(EComponentMobility::Movable);
	BarrilMesh->SetMassOverrideInKg(NAME_None, 100000000000000.0f); // Ajusta el valor según sea necesario
	SetRootComponent(BarrilMesh);

	////Movimiento
	//BarrilMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Barril_Movimiento"));
	//BarrilMovement->UpdatedComponent = BarrilMesh;
	//BarrilMovement->InitialSpeed = 100.0f;
	//BarrilMovement->MaxSpeed = 900.0f;
	//BarrilMovement->bRotationFollowsVelocity = false;
	//BarrilMovement->bShouldBounce = true;
	//BarrilMovement->Bounciness = 0.0f;
	//BarrilMovement->Friction = 0.2;

	//limites del barril
	inicial = 0;
	primero = 4.1;
	segundo = 10.5;

	//SpeedIncrease = 100.f;

	////Limites
	//MinYLimit = 2100.0f;
	//MaxYLimit = -1600.0f;
}

// Called when the game starts or when spawned
void ABarril::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABarril::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	eje = GetActorLocation();
	eje.X = 1280.0f;
	inicial += DeltaTime;
	if (eje.Z <= 910) incremento = 0.4;
	if (inicial < 3.9 + incremento) {
		eje.Y -= 10.4f;
		BarrilMesh->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
		SetActorLocation(eje);
	}

	if (inicial < 10) {
		eje.Y += 3.9f;
		BarrilMesh->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
		SetActorLocation(eje);

	}
	if (inicial >= 10) {
		inicial = 0;
	}
	BarrilMesh->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
	SetActorLocation(eje);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Cantidad del contenedor: %f"), inicial));

	//ubicacionActual = GetActorLocation();
	//velocidadActual = BarrilMovement->Velocity;
	//if (ubicacionActual.Y >= MinYLimit)
	//{
	//	BarrilMovement->Velocity = FVector(-velocidadActual.X, -115.0f, -115.0f);
	//}
	//else if (ubicacionActual.Y <= MaxYLimit)
	//{
	//	BarrilMovement->Velocity = FVector(velocidadActual.X, 115.0f, 115.0f);
	//}
	//ubicacionActual.X = 1280.0f;
	//BarrilMesh->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
}

//void ABarril::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
//{
//		Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
//	
//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Entro")));
//		FVector CurrentVelocity = BarrilMovement->Velocity;
//		FVector NewVelocity = CurrentVelocity.GetSafeNormal() * (CurrentVelocity.Size() + this->SpeedIncrease);
//		if (NewVelocity.Size() <= BarrilMovement->MaxSpeed) {
//			BarrilMovement->Velocity = NewVelocity;
//		}
//}
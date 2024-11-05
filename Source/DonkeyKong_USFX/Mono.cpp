// Fill out your copyright notice in the Description page of Project Settings.


#include "Mono.h"
#include "Proyectil.h"
#include "Barril.h"
#include "BarrilExplosivo.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMono::AMono()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mono(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	// Crear el componente de malla est?tica
	monoMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("puerta"));
	//SetStaticMesh() asigna una malla estatica a la instancia
	//CubeMeshAsset.Object obtiene el objeto malla y lo asigna a la instancia
	monoMesh->SetStaticMesh(mono.Object);
	// Establecer el componente de malla como el componente ra?z
	SetRootComponent(monoMesh);
	//Modifica la forma del objeto

	intervalo = 0.0f;

	//Patron singleton
	TArray<AActor*> Instancias;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMono::StaticClass(), Instancias);
	if (Instancias.Num() > 1)
	{
		//If exist at least one of them, set the instance with the first found one
		Instancia = Cast<AMono>(Instancias[0]);
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s Ya existe"), *Instancia->GetName()));
		//Then Destroy this Actor
		Destroy();
	}
}

// Called when the game starts or when spawned
void AMono::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMono::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	intervalo += DeltaTime;
	if (intervalo >= 2) {
		SpawnProyectil();
		intervalo = 0;
	}
}

void AMono::SpawnProyectil()
{
	ProjectileClass = ABarrilExplosivo::StaticClass();
	if (ProjectileClass)
	{
		// Obtener la ubicaci?n y rotaci?n del jugador
		FVector SpawnLocation = GetActorLocation() + FVector(0,-200,0); // Ajustar la distancia de spawn
		FRotator SpawnRotation = GetActorRotation();

		// Par?metros de spawn
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();
		// Spawnear el proyectil
		FVector ForwardDirection = FVector(0.0f, -1.f, 0.0f);
		ABarril* SpawnedProjectile1 = GetWorld()->SpawnActor<ABarril>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
	/*	ForwardDirection = FVector(0.0f, -1.f, 0.0f);
		ABarril* SpawnedProjectile2 = GetWorld()->SpawnActor<ABarril>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);*/
	}
}


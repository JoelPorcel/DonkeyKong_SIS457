// Fill out your copyright notice in the Description page of Project Settings.


#include "Muro.h"
#include "Components/BoxComponent.h"
#include "ComponenteExtra.h"
#include "BarrilExplosivo.h"
#include "DonkeyKong_USFXCharacter.h"

// Sets default values
AMuro::AMuro()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Architecture/Wall_400x300.Wall_400x300'"));

	MuroMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pared_mesh"));
	if (Mesh.Succeeded()) {
		MuroMesh->SetStaticMesh(Mesh.Object);
	}
	MuroMesh->SetRelativeScale3D(FVector(0.5, 0.5, 1.0));
	MuroMesh->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
	RootComponent = MuroMesh;

	MuroCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Pared_collision"));
	//MuroCollision->SetVisibility(true);
	MuroCollision->SetBoxExtent(FVector(200.0f, 30.0f, 150.0f));
	MuroCollision->SetRelativeLocation(FVector(215.0f, 0.0f, 150.0f));
	MuroCollision->SetCollisionProfileName(TEXT("Triger"));
	MuroCollision->SetupAttachment(GetRootComponent());
	MuroCollision->OnComponentBeginOverlap.AddDynamic(this, &AMuro::OnOverlapBegin);
	MuroCollision->OnComponentEndOverlap.AddDynamic(this, &AMuro::OnOverlapEnd);

	cambio = 0;
	ContadorCambio = 0;

	if (Componenteextra) {
		Componenteextra->CreateDefaultSubobject<UComponenteExtra>(TEXT("ComponenteExtra21"));
	}
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

void AMuro::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void AMuro::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AMuro::Mensaje()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, FString::Printf(TEXT("Esta es una pared normal")));
}

void AMuro::destruirBarril()
{
	if (Barril) {
		Barril->Destroy();
	}
}

void AMuro::armarMuro()
{
	GEngine->AddOnScreenDebugMessage(-1, 7.f, FColor::Yellow, FString::Printf(TEXT("Construyendo Muro")));
}

FString AMuro::ObtenerNombreDelMuro()
{
	return NombreDelMuro;
}

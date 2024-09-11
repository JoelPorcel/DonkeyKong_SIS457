// Fill out your copyright notice in the Description page of Project Settings.


#include "Plataforma.h"
// Sets default values
APlataforma::APlataforma()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//establece el componenete raiz de la malla
	static ConstructorHelpers::FObjectFinder<UStaticMesh> plataformaMesh(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube_Chamfer.1M_Cube_Chamfer'"));
	// Crear el componente de malla estática
	plataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("plataforma"));
	plataforma->SetStaticMesh(plataformaMesh.Object);
	SetRootComponent(plataforma);
	//Habitar fisicas de  la instancia
	//plataforma->SetSimulatePhysics(false);
	//Modifica la forma del objeto
	plataforma->SetWorldScale3D(FVector(1.9f, 3.0f, 0.5f));
	//Cambia el angulo del objeto (y,z,x)
	//plataforma->SetRelativeRotation(FRotator(0.0f, 0.0f, 5.0f));
	//Hacer invisible el objeto
	plataforma->SetVisibility(true);

}

// Called when the game starts or when spawned
void APlataforma::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

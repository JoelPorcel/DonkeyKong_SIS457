// Fill out your copyright notice in the Description page of Project Settings.


#include "Proyectil.h"
#include "Components/SphereComponent.h"
#include "BarrilSaltador.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/AudioComponent.h"


// Sets default values
AProyectil::AProyectil()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//malla
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectilMesh"));
	ProjectileMesh->SetStaticMesh(ProjectileMeshAsset.Object);
	ProjectileMesh->SetWorldScale3D(FVector(0.2f)); // Ajusta el tama?o seg?n sea necesario
	ProjectileMesh->SetMaterial(0, LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'")));
	RootComponent = ProjectileMesh;

	//Audio
	ProjectileAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("ProjectileAudio"));
	ProjectileAudioComponent->SetupAttachment(RootComponent);
	//static ConstructorHelpers::FObjectFinder<USoundBase> ProjectileSound(TEXT("SoundWave'/Game/Geometry/Meshes/Kyaa_-sound-effect.Kyaa_-sound-effect'"));
	//ProjectileAudioComponent->SetSound(ProjectileSound.Object);

	//Colicion
	ProjectileColision = CreateDefaultSubobject<USphereComponent>(TEXT("Projectil_Colision"));
	ProjectileColision->SetSphereRadius(50.0f);
	ProjectileColision->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
	ProjectileColision->SetVisibility(true);
	ProjectileColision->SetupAttachment(GetRootComponent());

	//movimiento
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	if (ProjectileMovement) {
		ProjectileMovement->UpdatedComponent = ProjectileMesh;
		ProjectileMovement->InitialSpeed = 1000.f; // Velocidad inicial lenta
		ProjectileMovement->MaxSpeed = 1000.f; // Velocidad m?xima
		ProjectileMovement->bRotationFollowsVelocity = true;
		ProjectileMovement->bShouldBounce = true;
		ProjectileMovement->Bounciness = 0.3f;
		ProjectileMovement->ProjectileGravityScale = 0.0f; // Sin gravedad
	}

	vidaUtil = 0.f;
}

void AProyectil::Initialize(const FVector& Direction)
{
	if (ProjectileMovement && ProjectileMovement != nullptr)
	{
		ProjectileMovement->Velocity = Direction * ProjectileMovement->InitialSpeed;
	}
}

// Called when the game starts or when spawned
void AProyectil::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AProyectil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	vidaUtil += DeltaTime;
	if (vidaUtil >= 5.0f) Destroy();
}

void AProyectil::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	// Aseg?rate de que el componente del otro actor tiene f?sica habilitada
	if ((OtherComp && OtherComp->IsSimulatingPhysics()) || Other->IsA(ABarrilSaltador::StaticClass()))
	{
		// Aplica un impulso en el punto de impacto en direcci?n contraria a la normal del impacto
		FVector ImpulseDirection = HitNormal * -1.0f;  // La direcci?n opuesta a la normal
		float ImpulseStrength = 100000.0f; // Ajusta la fuerza del impulso seg?n lo necesites
		OtherComp->AddImpulseAtLocation(ImpulseDirection * ImpulseStrength, HitLocation);
		//OtherComp->DestroyComponent();
		OtherComp->DestroyComponent();
	}
	// Luego, destruye el proyectil
	Destroy();
}



#include "Barril.h"
#include "Components/SphereComponent.h"
#include "ComponenteExtra.h"
#include "DonkeyKong_USFXCharacter.h"
#include "GameFramework/ProjectileMovementComponent.h"

ABarril::ABarril()
{
    PrimaryActorTick.bCanEverTick = true;

    // Configuraci?n del mesh
    static ConstructorHelpers::FObjectFinder<UStaticMesh> Barril(TEXT("StaticMesh'/Game/Barriles/Wooden_Barrel_1018213712.Wooden_Barrel_1018213712'"));

    BarrilMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla_Barril"));
    BarrilMesh->SetStaticMesh(Barril.Object);
    BarrilMesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.65f));
    BarrilMesh->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
    BarrilMesh->SetSimulatePhysics(true);
    BarrilMesh->SetMobility(EComponentMobility::Movable);
    BarrilMesh->BodyInstance.bLockXRotation = true;
    BarrilMesh->BodyInstance.bLockYRotation = true;
    BarrilMesh->BodyInstance.bLockZRotation = true;
    SetRootComponent(BarrilMesh);
    //Componenteextra = CreateDefaultSubobject<UComponenteExtra>(TEXT("ComponenteExtra"));


    //malla de colicion 
    BarrilColision = CreateDefaultSubobject<USphereComponent>(TEXT("Barril_Colision"));
    BarrilColision->SetSphereRadius(100.0f);
    BarrilColision->SetRelativeLocation(FVector(0.0f, 0.0f, -2.0f));
    BarrilColision->SetVisibility(true);
    BarrilColision->SetupAttachment(GetRootComponent());
    BarrilColision->OnComponentBeginOverlap.AddDynamic(this, &ABarril::OnOverlapBegin);

    //movimiento
    BarrilMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    if (BarrilMovement) {
        BarrilMovement->UpdatedComponent = BarrilMesh;
        BarrilMovement->InitialSpeed = 500.f; // Velocidad inicial lenta
        BarrilMovement->MaxSpeed = 1000.f; // Velocidad m?xima
        BarrilMovement->bRotationFollowsVelocity = true;
        //BarrilMovement->bShouldBounce = true;
        //BarrilMovement->Bounciness = 0.3f;
        //BarrilMovement->ProjectileGravityScale = 0.0f; // Sin gravedad
    }
    // Configuraci?n del movimiento
    LimiteMinY = -4400.0f;
    LimiteMaxY = 2400.0f;
    DireccionMovimiento = -1.0f;
    CoordenadaFijaX = 1208.0f;
	RotacionRate = 160.0f;
}

void ABarril::BeginPlay()
{
    Super::BeginPlay();

    // Establecer posici?n y rotaci?n inicial
    FVector PosicionInicial = GetActorLocation();
    PosicionInicial.X = CoordenadaFijaX;
    SetActorLocation(PosicionInicial);
   // SetActorRotation(FRotator(90.0f, 0.0f, 0.0f));
}

void ABarril::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Obtener la posici?n actual
    FVector PosicionActual = GetActorLocation();

    // Calcular nueva posici?n
    if(BarrilMovement->MaxSpeed > BarrilMovement->Velocity.Size())
	{
		BarrilMovement->Velocity = BarrilMovement->Velocity.GetSafeNormal() * BarrilMovement->MaxSpeed;
	}
    float NuevaPosicionY = PosicionActual.Y + (BarrilMovement->MaxSpeed * DireccionMovimiento * DeltaTime);

    // Verificar l?mites y cambiar direcci?n si es necesario
    if (NuevaPosicionY <= LimiteMinY)
    {
        DireccionMovimiento = 1.0f;
    }
    else if (NuevaPosicionY >= LimiteMaxY)
    {
        DireccionMovimiento = -1.0f;
    }

    // Actualizar posici?n manteniendo la rotaci?n fija
    FVector NuevaPosicion = FVector(CoordenadaFijaX, NuevaPosicionY, PosicionActual.Z);
    SetActorLocation(NuevaPosicion);
}

void ABarril::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void ABarril::destruirBarril()
{
    this->Destroy();
}

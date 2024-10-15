

#include "Barril.h"
#include "Components/SphereComponent.h"
#include "ComponenteExtra.h"
#include "DonkeyKong_USFXCharacter.h"

ABarril::ABarril()
{
    PrimaryActorTick.bCanEverTick = true;

    // Configuraci?n del mesh
    static ConstructorHelpers::FObjectFinder<UStaticMesh> Barril(TEXT("StaticMesh'/Game/Geometry/Meshes/Barril.Barril'"));

    BarrilMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla_Barril"));
    BarrilMesh->SetStaticMesh(Barril.Object);
    BarrilMesh->SetRelativeScale3D(FVector(1.5f, 1.5f, 2.0f));
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
    BarrilColision->SetSphereRadius(38.0f);
    BarrilColision->SetRelativeLocation(FVector(0.0f, 0.0f, 30.0f));
    BarrilColision->SetVisibility(true);
    BarrilColision->SetupAttachment(GetRootComponent());
    BarrilColision->OnComponentBeginOverlap.AddDynamic(this, &ABarril::OnOverlapBegin);


    // Configuraci?n del movimiento
    VelocidadMovimiento = 1000.0f;
    LimiteMinY = -1600.0f;
    LimiteMaxY = 2100.0f;
    DireccionMovimiento = 1.0f;
    CoordenadaFijaX = 1280.0f;
}

void ABarril::BeginPlay()
{
    Super::BeginPlay();

    // Establecer posici?n y rotaci?n inicial
    FVector PosicionInicial = GetActorLocation();
    PosicionInicial.X = CoordenadaFijaX;
    SetActorLocation(PosicionInicial);
    SetActorRotation(FRotator(90.0f, 0.0f, 0.0f));
}

void ABarril::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Obtener la posici?n actual
    FVector PosicionActual = GetActorLocation();

    // Calcular nueva posici?n
    float NuevaPosicionY = PosicionActual.Y + (VelocidadMovimiento * DireccionMovimiento * DeltaTime);

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
    // Asegurar que la rotaci?n se mantiene fija
    SetActorRotation(FRotator(90.0f, 0.0f, 0.0f));
}

void ABarril::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void ABarril::destruirBarril()
{
    this->Destroy();
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoElefante.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/Engine.h"

// Sets default values
AEnemigoElefante::AEnemigoElefante()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Crear el componente de malla esquelética
    SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
    // Cargar la malla esquelética desde el contenido (cambia la ruta a tu malla)
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("SkeletalMesh'/Game/AfricanAnimalsPack/Elephant/Meshes/SK_Elephant.SK_Elephant'"));
    if (MeshAsset.Succeeded())
    {
        SkeletalMesh->SetSkeletalMesh(MeshAsset.Object); // Asigna la malla esquelética
    }
    SkeletalMesh->SetupAttachment(RootComponent);
	SkeletalMesh->SetRelativeLocation(FVector(0.0f, -70.0f, -250.0f)); // Ajusta la posición según necesites
    // Cargar la animación
    static ConstructorHelpers::FObjectFinder<UAnimSequence> AnimationAsset(TEXT("AnimSequence'/Game/AfricanAnimalsPack/Elephant/Animations/ANIM_Elephant_Run.ANIM_Elephant_Run'"));
    if (AnimationAsset.Succeeded())
    {
        MyAnimationAsset = AnimationAsset.Object; // Asigna la animación
    }
    // Configurar la colisión de la malla esquelética
    // Configura la velocidad de movimiento
    GetCharacterMovement()->MaxWalkSpeed = 600.0f; // Ajusta la velocidad según necesites
	//GetCharacterMovement()->GravityScale = 20.0f;
    //GetCharacterMovement()->GravityScale = 0.0f;
}

// Called when the game starts or when spawned
void AEnemigoElefante::BeginPlay()
{
	Super::BeginPlay();
    if (MyAnimationAsset && SkeletalMesh)
    {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Animación cargada"));
        SkeletalMesh->PlayAnimation(MyAnimationAsset, true); // false significa que no se repetirá en bucle
    }
    APawn* Player1 = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (Player1) {
        GetWorld()->GetTimerManager().SetTimer(Timer,[this, Player1]() {atacar(); },0.009f,true);
    }
}

// Called every frame
void AEnemigoElefante::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    // Obtener el Pawn del jugador
   // APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
   // if (PlayerPawn)
   // {
   //     float Distance = FVector::Dist(GetActorLocation(), PlayerPawn->GetActorLocation());

   //     // Verificar si el jugador está dentro del rango de detección
   //     if (Distance <= 2000.0f) // Puedes ajustar este rango de detección
   //     {
   //         // Moverse hacia el jugador
			////GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Moviendo hacia el jugador"));
   //         atacarJugador(PlayerPawn);
   //     }
   // }
}

// Called to bind functionality to input
void AEnemigoElefante::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemigoElefante::atacarJugador(APawn* PlayerPawn)
{
    if (PlayerPawn)
    {
        // Obtener la dirección hacia el jugador
        FVector Direction = (PlayerPawn->GetActorLocation() - GetActorLocation()).GetSafeNormal();
        // Mover directamente el actor
        FVector NewLocation = GetActorLocation() + (Direction * 10.0f); 
        SetActorLocation(NewLocation);
        FRotator NewRotation = Direction.Rotation();
        NewRotation.Pitch = 0.0f;
        NewRotation.Roll = 0.0f;
		NewRotation.Yaw > 0 ? NewRotation.Yaw = 0 : NewRotation.Yaw = 180;
        SetActorRotation(NewRotation);
    }
}

void AEnemigoElefante::atacar()
{
	APawn* Player2 = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (Player2) {
		atacarJugador(Player2);
	}
}

void AEnemigoElefante::vigilar()
{
}

void AEnemigoElefante::eliminar()
{
}

void AEnemigoElefante::spawn(TMap<int, APlataforma*> _Posicion)
{
    TArray<int> Llaves;
    _Posicion.GetKeys(Llaves);
	int Llave = Llaves[FMath::RandRange(0, Llaves.Num() - 1)];
    if (_Posicion[Llave]) {
        Plataforma = _Posicion[Llave];
        if (Plataforma)
        {
            FVector Posicion3 = Plataforma->GetActorLocation();
            // Ajusta la posición nuevamente si es necesario
            Posicion3.Z += 100.0f;
            SetActorLocation(Posicion3);
        }
    }
}


// Iniciar el timer para seguir al jugador
//GetWorld()->GetTimerManager().SetTimer(FollowPlayerTimerHandle, this, &AEnemigoElefante::FollowPlayer, 0.1f, true, 0.0f);
//GetWorld()->GetTimerManager().SetTimer(FollowPlayerTimerHandle, this, &AEnemigoElefante::StopFollowingPlayer, 30.0f, false);
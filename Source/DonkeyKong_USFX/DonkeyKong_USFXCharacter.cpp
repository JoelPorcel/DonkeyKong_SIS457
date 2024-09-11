// Copyright Epic Games, Inc. All Rights Reserved.

#include "DonkeyKong_USFXCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Proyectil.h"
#include "Engine/World.h"
#include "UObject/ConstructorHelpers.h"

ADonkeyKong_USFXCharacter::ADonkeyKong_USFXCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 3500.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,1000.f);
	CameraBoom->SetRelativeRotation(FRotator(0.f,180.f,0.f));

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1300.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	//salto alto
	leftmin = 2100.0f;
	leftmax = 1700.0f;
	rightmin = -1300.0f;
	rightmax = -1700.0f;

	InitializeEsferaClass();
}

void ADonkeyKong_USFXCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	salto();
}

void ADonkeyKong_USFXCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &ADonkeyKong_USFXCharacter::MoveRight);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &ADonkeyKong_USFXCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ADonkeyKong_USFXCharacter::TouchStopped);
	PlayerInputComponent->BindAction("SpawnEsfera", IE_Pressed, this, &ADonkeyKong_USFXCharacter::SpawnEsfera);
}

void ADonkeyKong_USFXCharacter::salto()
{
	posicionActual = GetActorLocation();
	if ((posicionActual.Y <= leftmin && posicionActual.Y >= leftmax) || (posicionActual.Y <= rightmin && posicionActual.Y >= rightmax)) {
		GetCharacterMovement()->JumpZVelocity = 1300.f;
	}
	else GetCharacterMovement()->JumpZVelocity = 1300.f;
}

void ADonkeyKong_USFXCharacter::MoveRight(float Value)
{
	// add movement in that direction
	AddMovementInput(FVector(0.f,-1.f,0.f), Value);
}

void ADonkeyKong_USFXCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}

void ADonkeyKong_USFXCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}

void ADonkeyKong_USFXCharacter::SpawnEsfera()
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Tecla Z presionada"));
    }

    if (EsferaClass)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("EsferaClass está configurada"));
        }

        UWorld* World = GetWorld();
        if (World)
        {
            FVector SpawnLocation = GetActorLocation() + GetActorForwardVector() * 100.f;
            FRotator SpawnRotation = GetActorRotation();

            AProyectil* SpawnedEsfera = World->SpawnActor<AProyectil>(EsferaClass, SpawnLocation, SpawnRotation);
            if (SpawnedEsfera)
            {
                // Inicializa la esfera con la dirección del personaje
                FVector Direction = GetActorForwardVector();
                SpawnedEsfera->Initialize(Direction);

                if (GEngine)
                {
                    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Esfera spawneada"));
                }
            }
            else
            {
                if (GEngine)
                {
                    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Fallo al spawnear la esfera"));
                }
            }
        }
        else
        {
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("World no válido"));
            }
        }
    }
    else
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("EsferaClass no configurada"));
        }
    }
}

void ADonkeyKong_USFXCharacter::InitializeEsferaClass()
{
    EsferaClass = AProyectil::StaticClass();
    if (EsferaClass)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("EsferaClass configurada correctamente"));
        }
    }
    else
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No se pudo encontrar la clase Esfera"));
        }
    }
}

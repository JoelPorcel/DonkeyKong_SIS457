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
	CameraBoom->TargetArmLength = 2500.f;
	CameraBoom->SocketOffset = FVector(0.f, 0.f, 700.f);
	CameraBoom->SetRelativeRotation(FRotator(0.f, 180.f, 0.f));

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

	//vidas 
	vidas = 3;
	condicion = 800.0f;
	puntaje = 0;
	sumarpuntos = 150.0f;
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Magenta, FString::Printf(TEXT("Vidas: %d"), GetVidas()));
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Magenta, FString::Printf(TEXT("Puntaje actual: %.1f"), GetPuntaje()));
	}
}

void ADonkeyKong_USFXCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	salto();
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Magenta, FString::Printf(TEXT("Puntaje actual: %.1f"), GetPuntaje()));
	ControlPuntos();
	ControlVidas();
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
	AddMovementInput(FVector(0.f, -1.f, 0.f), Value);
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
	ProjectileClass = AProyectil::StaticClass();
	if (ProjectileClass)
	{
		// Obtener la ubicaci?n y rotaci?n del jugador
		FVector SpawnLocation = GetActorLocation() + GetActorForwardVector() * 100; // Ajustar la distancia de spawn
		FRotator SpawnRotation = GetActorRotation();

		// Par?metros de spawn
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();
		// Spawnear el proyectil
		FVector ForwardDirection = GetActorForwardVector();
		if (ForwardDirection.Y >= 0.99) {
			//SpawnLocation.Y += 200.0f;
			AProyectil* SpawnedProjectile1 = GetWorld()->SpawnActor<AProyectil>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
			SpawnedProjectile1->Initialize(ForwardDirection);
			//SpawnLocation.Y -= 100.0f;
			//AProyectil* SpawnedProjectile2 = GetWorld()->SpawnActor<AProyectil>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
			//SpawnedProjectile2->Initialize(ForwardDirection);
		}
		else if (ForwardDirection.Y <= -0.99) {
			//pawnLocation.Y -= 200.0f;
			AProyectil* SpawnedProjectile2 = GetWorld()->SpawnActor<AProyectil>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
			SpawnedProjectile2->Initialize(ForwardDirection);
			//SpawnLocation.Y += 100.0f;
			//AProyectil* SpawnedProjectile2 = GetWorld()->SpawnActor<AProyectil>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
			//SpawnedProjectile2->Initialize(ForwardDirection);
		}
	}
}

void ADonkeyKong_USFXCharacter::ControlPuntos()
{
	FVector ubicacion = GetActorLocation();
	if (ubicacion.Z >= condicion) {
		puntaje += 100;
		condicion += 800.0f;
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Emerald, FString::Printf(TEXT("Puntaje actual: %.1f"), GetPuntaje()));
	}
	if (puntaje >= sumarpuntos) {
		vidas++;
		sumarpuntos += 150.0f;
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Obtuviste una vida extra, vidas: %d"), GetVidas()));
	}
	if (puntaje <= 0) puntaje = 0;
}

void ADonkeyKong_USFXCharacter::ControlVidas()
{
	if (vidas <= 0) {
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Perdiste el juego ")));
		Destroy();
	}
}

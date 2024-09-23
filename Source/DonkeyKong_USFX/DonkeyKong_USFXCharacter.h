// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DonkeyKong_USFXCharacter.generated.h"

class AProyectil;
class ABarrilSaltador;

UCLASS(config=Game)
class ADonkeyKong_USFXCharacter : public ACharacter
{
	GENERATED_BODY()

	virtual void Tick(float DeltaTime) override;

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	//Salto alto
	UPROPERTY(VisibleAnywhere)
	float leftmin;

	UPROPERTY(VisibleAnywhere)
	float leftmax;

	UPROPERTY(VisibleAnywhere)
	float rightmin;

	UPROPERTY(VisibleAnywhere)
	float rightmax;

	UPROPERTY(VisibleAnywhere)
	FVector posicionActual;

	//objeto proyectil
	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	TSubclassOf<AProyectil> ProjectileClass;

protected:

	/** Called for side to side input */
	void MoveRight(float Val);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void salto();
	// End of APawn interface


public:
	ADonkeyKong_USFXCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	void SpawnEsfera();
};

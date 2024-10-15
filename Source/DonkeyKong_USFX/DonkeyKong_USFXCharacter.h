// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Proyectil.h"
#include "GameFramework/Character.h"
#include "DonkeyKong_USFXCharacter.generated.h"

UCLASS(config = Game)
class ADonkeyKong_USFXCharacter : public ACharacter
{
	GENERATED_BODY()

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

	void SpawnEsfera();
	// End of APawn interface
	int vidas;
	float puntaje;
	float sumarpuntos;
	float condicion;
	void ControlPuntos();
	void ControlVidas();


public:
	ADonkeyKong_USFXCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	virtual void Tick(float DeltaTime) override;

	FORCEINLINE int GetVidas() { return vidas; }
	FORCEINLINE void SetVidas(int _vidas){ vidas = _vidas; }
	FORCEINLINE float GetPuntaje() { return puntaje; }
	FORCEINLINE void SetPuntaje(float _puntaje) { puntaje = _puntaje; }
};

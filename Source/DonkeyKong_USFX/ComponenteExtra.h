// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ComponenteExtra.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DONKEYKONG_USFX_API UComponenteExtra : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UComponenteExtra();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Desaparecer(AActor* actor);

	void Aparecer(AActor* actor);

	void Subir(AActor* actor);

	void Bajar(AActor* actor);
		
};

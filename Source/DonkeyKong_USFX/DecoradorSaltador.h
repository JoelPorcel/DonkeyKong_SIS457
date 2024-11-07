// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Decorador.h"
#include "DecoradorSaltador.generated.h"

UCLASS()
class DONKEYKONG_USFX_API ADecoradorSaltador : public ADecorador
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADecoradorSaltador();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void setCorrer(float _correr) override;
	void setSaltar(float _salto) override;
	float getCorrer() override;
	float getSaltar() override;
};

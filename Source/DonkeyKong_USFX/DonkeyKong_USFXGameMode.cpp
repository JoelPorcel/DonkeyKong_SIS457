// Copyright Epic Games, Inc. All Rights Reserved.

#include "DonkeyKong_USFXGameMode.h"
#include "Plataforma.h"
#include "PlataformaMovible.h"
#include "PlataformaSuvible.h"
#include "Barril.h"
#include "BarrilSaltador.h"
#include "Mono.h"
#include "DonkeyKong_USFXCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADonkeyKong_USFXGameMode::ADonkeyKong_USFXGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ADonkeyKong_USFXGameMode::BeginPlay()
{
	Posicion = FVector(1206.8f, 1700.f, 180.f);
	Rotacion = FRotator(0.0f, 0.0f, 2.0f);
	Spawn = FVector(1280.0f, 1900.0f, 2940.0f);
	random = FMath::RandRange(0, 3);
	enemigosCant = FMath::RandRange(3, 5); //para enemigos
	signo = 1.0f;
	tiempo = 0.0f;
	constant_z = 8.3f;
	for (int i = 0; i < 6; i++) {
		//plataformas
		enemigo = Posicion;
		ID = Plataformas.Num();
		desicion = FMath::RandRange(1, 2);
		componentes = FMath::RandRange(3, 13);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("desicion: %d"), desicion));
		for (int t = componentes; t >= 1; t--) {
			ID = Plataformas.Num();
			movimiento = FMath::RandRange(3, 5);
			if (desicion == 1 && t != 1) {
				if (t == movimiento || t + 1 == movimiento || t == movimiento + 1) {
					Posicion += FVector(0.0f, -290.f * signo, constant_z);
					Plataformas.Add(ID, GetWorld()->SpawnActor<APlataformaSuvible>(APlataformaSuvible::StaticClass(), Posicion, Rotacion));
				}
				else if (t != movimiento) {
					Posicion += FVector(0.0f, -290.f * signo, constant_z);
					Plataformas.Add(ID, GetWorld()->SpawnActor<APlataforma>(APlataforma::StaticClass(), Posicion, Rotacion));
				}
			}
			else {
				if (t == movimiento) {
					Posicion += FVector(0.0f, -290.f * signo, constant_z - constant_z);
					Plataformas.Add(ID, GetWorld()->SpawnActor<APlataformaSuvible>(APlataformaSuvible::StaticClass(), Posicion, FRotator::ZeroRotator));
				}
				else if (t != movimiento) {
					Posicion += FVector(0.0f, -290.f * signo, constant_z - constant_z);
					Plataformas.Add(ID, GetWorld()->SpawnActor<APlataforma>(APlataforma::StaticClass(), Posicion, FRotator::ZeroRotator));
				}
			}
		}
		if (i == random) {
			Aparicion = Posicion;
			Aparicion.Y += -450 * signo;
			if (Aparicion.Y > 2113) Aparicion.Y += 900;
			Plataformas.Add(ID, GetWorld()->SpawnActor<APlataformaMovible>(APlataformaMovible::StaticClass(), Aparicion, FRotator::ZeroRotator));
			Aparicion += FVector(0.0f, -1300.0f * signo, 0.0f);
			if (Aparicion.Y > 2113) Aparicion.Y += -750;
			Plataformas.Add(ID, GetWorld()->SpawnActor<APlataforma>(APlataforma::StaticClass(), Aparicion, FRotator::ZeroRotator));

		}
		signo *= -1.0f;
		Posicion += FVector(0.0f, -275 * signo, 400.f);
		Rotacion.Roll *= -1;
		enemigo_ = Posicion;
		Pu = enemigo;
		control = FMath::RandRange(1, 2);
		if ((control == 1 && Enemigos.Num() < 6) || Enemigos.Num() < 2 && i<2) {
			Pu.Z = FMath::RandRange(enemigo_.Z, enemigo.Z);
			Pu.Y = FMath::RandRange(enemigo_.Y, enemigo.Y);
			Enemigos.Add(GetWorld()->SpawnActor<AMono>(AMono::StaticClass(), Pu, FRotator::ZeroRotator));
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Cantidad del contenedor: %d"), Plataformas.Num()));
}

void ADonkeyKong_USFXGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Barriles
	Spawn = FVector(1280.0f, 1900.0f, 2980.0f);
	random = FMath::RandRange(1, 10);
	tiempo += DeltaTime;
	if (Barriles.Num() < 30 && tiempo >= 5 && random >= 1 && random <= 7) {
		Barriles.Add(GetWorld()->SpawnActor<ABarril>(ABarril::StaticClass(), Spawn, FRotator::ZeroRotator));
		tiempo = 0;
	}
	else if (Barriles.Num() < 30 && tiempo >= 5 && random >= 8) {
		Barriles.Add(GetWorld()->SpawnActor<ABarrilSaltador>(ABarrilSaltador::StaticClass(), Spawn, FRotator::ZeroRotator));
		tiempo = 0;
	}
}


/*tiempo += DeltaTime;
if (tiempo >= 0.5f && Plataformap.Num() > 0 ) {
	destruir = Plataformas[Plataformap.Num()-1];
	destruir->Destroy();
	Plataformas.RemoveAt(Plataformas.Num() - 1);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Cantidad del contenedor: %d"), Plataformas.Num()));
	tiempo = 00.f;
}*/
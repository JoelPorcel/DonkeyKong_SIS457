// Copyright Epic Games, Inc. All Rights Reserved.

#include "DonkeyKong_USFXGameMode.h"
#include "Plataforma.h"
#include "BarrilComun.h"
#include "BarrilExplosivo.h"
#include "BarrilSaltador.h"
#include "Mono.h"
#include "Muro.h"
#include "MuroCongelado.h"
#include "MuroLadrillo.h"
#include "MuroPegajoso.h"
#include "MuroEspinoso.h"
#include "MuroElectrico.h"
#include "Componenteextra.h"
#include "DonkeyKong_USFXCharacter.h"
#include "UObject/ConstructorHelpers.h"

#include "TiendaMuros.h"
#include "FabricaMuros.h"

ADonkeyKong_USFXGameMode::ADonkeyKong_USFXGameMode()
{
	// set default pawn class to our Blueprinted character
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	Paredes.Add(AMuroCongelado::StaticClass());
	Paredes.Add(AMuroCongelado::StaticClass());
	Paredes.Add(AMuroLadrillo::StaticClass());
	Paredes.Add(AMuroPegajoso::StaticClass());
	Paredes.Add(AMuroEspinoso::StaticClass());
}

void ADonkeyKong_USFXGameMode::BeginPlay()
{

	AFabricaMuros* tienda = GetWorld()->SpawnActor<ATiendaMuros>(ATiendaMuros::StaticClass());
	AMuro* muro = tienda->EncargarMuro("Muro espinoso", FVector(580, 1040, 110), FRotator::ZeroRotator);
	GEngine->AddOnScreenDebugMessage(-1, 7.f, FColor::Purple, FString::Printf(TEXT("%s"), *muro->ObtenerNombreDelMuro()));
	AMuro* muro2 = tienda->EncargarMuro("Muro ladrillo", FVector(580, 800, 110), FRotator::ZeroRotator);
	GEngine->AddOnScreenDebugMessage(-1, 7.f, FColor::Purple, FString::Printf(TEXT("%s"), *muro2->ObtenerNombreDelMuro()));

	Timer = 0;// muros
	CantidadMuros = 0;//muros
	ID = 0; // plataformas
	Posicion = FVector(1206.8f, 1700.f, 180.f);//platafprmas
	Rotacion = FRotator(0.0f, 0.0f, 2.0f);//plataformas
	Spawn = FVector(1280.0f, 1900.0f, 2940.0f); //barriles
	enemigosCant = FMath::RandRange(3, 5); //para enemigos
	signo = 1.0f; //plataformas
	tiempo = 0.0f;//barriles
	constant_z = 8.3f; //plataformas
	int sum = 2;
	for (int i = 0; i < 6; i++) {
		limitePlataformas = Plataformas.Num() + sum;
		random = FMath::RandRange(1, 2); //plataformas
		for (int j = 0; j < 10; j++) {
			if (random == 1 && i != 5) {
				Posicion += FVector(0.0f, -290.f * signo, constant_z);
				Plataformas.Add(++ID, GetWorld()->SpawnActor<APlataforma>(APlataforma::StaticClass(), Posicion, Rotacion));
			}
			else if (random == 2 || i == 5) {
				Posicion += FVector(0.0f, -290.f * signo, constant_z - constant_z);
				Plataformas.Add(++ID, GetWorld()->SpawnActor<APlataforma>(APlataforma::StaticClass(), Posicion, FRotator::ZeroRotator));
			}
		}
		PlataformasMovimiento();
		Posicion += FVector(0.0f, -290.f * signo, constant_z);
		signo *= -1.0f;
		Posicion += FVector(0.0f, -275 * signo, 400.f);
		Rotacion.Roll *= -1;
		sum += 2;
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Cantidad del contenedor: %d"), Plataformas.Num()));

	//for (int e = 0; e < enemigosCant; e++) {
	//	GenerarEnemigos();
	//}
}

void ADonkeyKong_USFXGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Timer += DeltaTime;
	if (Timer >= 3 && CantidadMuros <= 4) {
		GenerarParedesAleatorias();
		Timer = 0;
		CantidadMuros++;
	}
	//Barriles
	Spawn = FVector(1280.0f, 1700.0f, 2980.0f);
	random = FMath::RandRange(1, 10);
	tiempo += DeltaTime;
	if (tiempo >= 5) {
		random = FMath::RandRange(1, 10);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("El numero random es: %d"), random));
		if (Barriles.Num() < 30 && random >= 1 && random <= 3) {
			Barriles.Add(GetWorld()->SpawnActor<ABarrilExplosivo>(ABarrilExplosivo::StaticClass(), Spawn, FRotator::ZeroRotator));
			tiempo = 0;
		}
		else if (Barriles.Num() < 30 && random >= 4 && random <= 7) {
			Barriles.Add(GetWorld()->SpawnActor<ABarrilComun>(ABarrilComun::StaticClass(), Spawn, FRotator::ZeroRotator));
			tiempo = 0;
		}
		else if (Barriles.Num() < 30 && random >= 8) {
			Barriles.Add(GetWorld()->SpawnActor<ABarrilSaltador>(ABarrilSaltador::StaticClass(), Spawn, FRotator::ZeroRotator));
			tiempo = 0;
		}
	}

}

void ADonkeyKong_USFXGameMode::PlataformasMovimiento()
{
	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Blue, FString::Printf(TEXT("limite inicial: %d"), limitePlataformas));
	while (true) {
		random = FMath::RandRange(limitePlataformas, Plataformas.Num());
		if (random % 10 != 0 || random % 10 != 1) break;
	}


	// Verificar si la llave 'random' existe en el mapa antes de proceder
	if (Plataformas.Contains(random))
	{
		APlataforma* moverse = Cast<APlataforma>(Plataformas[random]);
		int mob = FMath::RandRange(1, 2);
		if (mob == 1) {
			moverse->SetMoverseY(true);
		}
		else {
			moverse->SetMoverseZ(true);
		}
		moverse->SetMoverseY(true);
	}

	if (Plataformas.Contains(random - 1))
	{
		AActor* destruir = Plataformas[random - 1];
		destruir->Destroy();
		Plataformas.Remove(random - 1);
	}

	if (Plataformas.Contains(random + 1))
	{
		AActor* destruir = Plataformas[random + 1];
		destruir->Destroy();
		Plataformas.Remove(random + 1);
	}
}

void ADonkeyKong_USFXGameMode::GenerarEnemigos()
{
	PlataformaAleatoria = FMath::RandRange(1, Plataformas.Num());
	if (Plataformas.Contains(PlataformaAleatoria) && Plataformas[PlataformaAleatoria] != nullptr) {
		enemigoAleatorio = Plataformas[PlataformaAleatoria]->GetActorLocation();
		enemigoAleatorio.Z += 70.f;
		mono = GetWorld()->SpawnActor<AMono>(AMono::StaticClass(), enemigoAleatorio, FRotator::ZeroRotator);
		//Enemigos.Add(mono);
	}
}

void ADonkeyKong_USFXGameMode::GenerarParedesAleatorias()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Aparece pared")));
	PlataformaAleatoria = FMath::RandRange(0, Plataformas.Num() - 1);
	if (Plataformas.Contains(PlataformaAleatoria)) {
		UbicacionAleatoria = Plataformas[PlataformaAleatoria]->GetActorLocation();
		UbicacionAleatoria.Z += 50.f;
		UbicacionAleatoria.X += 180.f;
		if (Paredes.Num() > 0 && CantidadMuros < 4) {
			IndiceAleatorio = FMath::FRandRange(0, Paredes.Num() - 1);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("pared seleccionada: %d"), IndiceAleatorio));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("num paredes: %d"), Paredes.Num()));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Indice Aleatorio: %d"), IndiceAleatorio));
			ParedesAleatorias = Paredes[IndiceAleatorio];
			Muros.Add(GetWorld()->SpawnActor<AMuro>(ParedesAleatorias, UbicacionAleatoria, FRotator::ZeroRotator));
		}
	}
}

void ADonkeyKong_USFXGameMode::ConstruccionMuros()
{
}

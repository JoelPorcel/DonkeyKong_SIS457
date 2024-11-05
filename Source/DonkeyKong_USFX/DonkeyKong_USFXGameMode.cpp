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

#include "Kismet/GameplayStatics.h"

#include "BuilderNiveles.h"
#include "BuilderTipoA.h"
#include "BuilderTipoB.h"
#include "Arquitecto.h"
#include "EnemigosFacade.h"
#include "EnemigoElefante.h"
#include "DecoradorCorredor.h"
#include "DecoradorSaltador.h"

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
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("Constructor de GameMode en el mundo de DOnkey Kong")));
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
	constant_z = 20.f; //plataformas
	int sum = 2;
	
	Constructor = GetWorld()->SpawnActor<ABuilderTipoA>(ABuilderTipoA::StaticClass());
	Ingeniero = GetWorld()->SpawnActor<AArquitecto>(AArquitecto::StaticClass());
	//Ingeniero->EstablecerConstructorNiveles(Constructor);
	//Ingeniero->ConstruirNivel1(5,10,Posicion,1);
	//Escenario = Ingeniero->obtenerEscenario();

	//Posicion.Y -= 1600.f;
	Constructor2 = GetWorld()->SpawnActor<ABuilderTipoB>(ABuilderTipoB::StaticClass());
	Ingeniero->EstablecerConstructorNiveles(Constructor2);
	Ingeniero->ConstruirNivel1(5, 10, Posicion, 1);
	PosicionMapa = Ingeniero->obtenerPlataformas();
	//segundos = 0;	

	//AEnemigosFacade* Facade = GetWorld()->SpawnActor<AEnemigosFacade>(AEnemigosFacade::StaticClass());
	//Facade->spawn("elefante", 1, PosicionMapa);
	//AEnemigoElefante* elefante = GetWorld()->SpawnActor<AEnemigoElefante>(AEnemigoElefante::StaticClass(), FVector(1550,-1210,450),FRotator::ZeroRotator);
	// 
	// 
	APawn* Player1 = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	ADecoradorCorredor* saltadorD = GetWorld()->SpawnActor<ADecoradorCorredor>(ADecoradorCorredor::StaticClass());
	saltadorD->setJugador(Player1);
	saltadorD->corredor();
	ADecoradorSaltador* saltadorA = GetWorld()->SpawnActor<ADecoradorSaltador>(ADecoradorSaltador::StaticClass());
	saltadorA->setJugador(saltadorD);
	saltadorA->saltador();
}

void ADonkeyKong_USFXGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	segundos += DeltaTime;
	if (segundos >= 10) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Cambio de nivel")));
		//UGameplayStatics::OpenLevel(GetWorld(), FName("nivel2"));
		segundos = 0;
	}

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


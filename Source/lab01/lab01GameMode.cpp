#include "lab01GameMode.h"
#include "TimerManager.h"
#include "Engine/World.h"

// Includes de tus clases
#include "EAHelicoptero.h"
#include "EAAvion.h"
#include "EADron.h"
#include "ETSoldado.h"
#include "ETTanque.h"
#include "ETCamion.h"
#include "ETBlindado.h"
#include "EABarco.h"
#include "EALancha.h"
#include "EAMotoAcuatica.h"

void Alab01GameMode::BeginPlay()
{
	Super::BeginPlay();
	// Empezamos con la Fase 1: Solo Terrestres
	SpawnCuadrilla(1);
	GetWorldTimerManager().SetTimer(TimerRevision, this, &Alab01GameMode::RevisarEstadoCuadrilla, 1.0f, true);
}

void Alab01GameMode::SpawnCuadrilla(int32 NumeroDeFase)
{
	float InicioX = -2000.0f; // Punto de partida
	float SeparacionX = 600.0f; // Espacio entre cada uno para que no choquen
	float PosY = 0.0f;

	if (NumeroDeFase == 1) // --- OLA 1: SOLO TERRESTRES ---
	{
		CuadrillaActual.Add(GetWorld()->SpawnActor<AETTanque>(AETTanque::StaticClass(), FVector(InicioX, PosY, 100), FRotator::ZeroRotator));
		CuadrillaActual.Add(GetWorld()->SpawnActor<AETSoldado>(AETSoldado::StaticClass(), FVector(InicioX + SeparacionX, PosY, 100), FRotator::ZeroRotator));
		CuadrillaActual.Add(GetWorld()->SpawnActor<AETCamion>(AETCamion::StaticClass(), FVector(InicioX + (SeparacionX * 2), PosY, 100), FRotator::ZeroRotator));
		CuadrillaActual.Add(GetWorld()->SpawnActor<AETBlindado>(AETBlindado::StaticClass(), FVector(InicioX + (SeparacionX * 3), PosY, 100), FRotator::ZeroRotator));
	}
	else if (NumeroDeFase == 2) // --- OLA 2: SOLO AÉREOS ---
	{
		CuadrillaActual.Add(GetWorld()->SpawnActor<AEAHelicoptero>(AEAHelicoptero::StaticClass(), FVector(InicioX, PosY, 600), FRotator::ZeroRotator));
		CuadrillaActual.Add(GetWorld()->SpawnActor<AEAAvion>(AEAAvion::StaticClass(), FVector(InicioX + SeparacionX, PosY, 800), FRotator::ZeroRotator));
		CuadrillaActual.Add(GetWorld()->SpawnActor<AEADron>(AEADron::StaticClass(), FVector(InicioX + (SeparacionX * 2), PosY, 700), FRotator::ZeroRotator));
	}
	else if (NumeroDeFase == 3) // --- OLA 3: SOLO ACUÁTICOS ---
	{
		CuadrillaActual.Add(GetWorld()->SpawnActor<AEABarco>(AEABarco::StaticClass(), FVector(InicioX, PosY, 50), FRotator::ZeroRotator));
		CuadrillaActual.Add(GetWorld()->SpawnActor<AEALancha>(AEALancha::StaticClass(), FVector(InicioX + SeparacionX, PosY, 50), FRotator::ZeroRotator));
		CuadrillaActual.Add(GetWorld()->SpawnActor<AEAMotoAcuatica>(AEAMotoAcuatica::StaticClass(), FVector(InicioX + (SeparacionX * 2), PosY, 50), FRotator::ZeroRotator));
	}
}

void Alab01GameMode::RevisarEstadoCuadrilla()
{
	CuadrillaActual.RemoveAll([](AEnemigoBase* E) { return !IsValid(E); });

	// Si se mueren todos, pasamos a la siguiente familia
	if (CuadrillaActual.Num() == 0)
	{
		if (FaseActual < 3)
		{
			FaseActual++;
			SpawnCuadrilla(FaseActual);
		}
	}
}
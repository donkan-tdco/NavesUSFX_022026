#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EnemigoBase.h"
#include "lab01GameMode.generated.h"

UCLASS()
class LAB01_API Alab01GameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	void SpawnCuadrilla(int32 NumeroDeCuadrilla);
	void RevisarEstadoCuadrilla();

	FTimerHandle TimerRevision; // Sin tilde
	TArray<AEnemigoBase*> CuadrillaActual;
	int32 FaseActual = 1;
};
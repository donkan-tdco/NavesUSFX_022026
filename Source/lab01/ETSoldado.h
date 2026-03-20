#pragma once

#include "CoreMinimal.h"
#include "EnemigoTerrestre.h" // Hereda de Terrestre
#include "ETSoldado.generated.h"

UCLASS()
class LAB01_API AETSoldado : public AEnemigoTerrestre
{
	GENERATED_BODY()

public:
	AETSoldado();
};
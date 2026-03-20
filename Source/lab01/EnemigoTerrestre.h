#pragma once
#include "CoreMinimal.h"
#include "EnemigoBase.h"
#include "EnemigoTerrestre.generated.h"

UCLASS()
class LAB01_API AEnemigoTerrestre : public AEnemigoBase
{
    GENERATED_BODY()
public:
    AEnemigoTerrestre();
    virtual void MoverEnemigo(float DeltaTime) override;
};
#pragma once
#include "CoreMinimal.h"
#include "EnemigoBase.h"
#include "EnemigoAereo.generated.h"

UCLASS()
class LAB01_API AEnemigoAereo : public AEnemigoBase
{
    GENERATED_BODY()
public:
    AEnemigoAereo();
    virtual void MoverEnemigo(float DeltaTime) override;
};
#pragma once
#include "CoreMinimal.h"
#include "EnemigoBase.h"
#include "EnemigoAcuatico.generated.h"

UCLASS()
class LAB01_API AEnemigoAcuatico : public AEnemigoBase
{
    GENERATED_BODY()
public:
    AEnemigoAcuatico();
    virtual void MoverEnemigo(float DeltaTime) override;
};
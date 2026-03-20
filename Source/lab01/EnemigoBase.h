#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemigoBase.generated.h"

UCLASS()
class LAB01_API AEnemigoBase : public AActor
{
    GENERATED_BODY()

public:
    AEnemigoBase();

    // La malla que heredarán todos
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemigo")
    class UStaticMeshComponent* MeshEnemigo;

    // Función de movimiento que usará el Tick
    virtual void MoverEnemigo(float DeltaTime);

protected:
    virtual void BeginPlay() override;

    // Variables de dirección que eligen un rumbo al azar
    float DirX;
    float DirY;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
    float Velocidad = 300.0f;

public:
    virtual void Tick(float DeltaTime) override;
};
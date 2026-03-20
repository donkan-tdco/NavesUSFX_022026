#include "EnemigoTerrestre.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

AEnemigoTerrestre::AEnemigoTerrestre() : AEnemigoBase()
{
    // Buscamos el Cubo básico
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

    if (CubeMesh.Succeeded())
    {
        MeshEnemigo->SetStaticMesh(CubeMesh.Object);
    }
}

void AEnemigoTerrestre::MoverEnemigo(float DeltaTime)
{
    FVector NuevaPos = GetActorLocation() + (FVector(DirX, 0.0f, 0.0f) * Velocidad * DeltaTime);
    SetActorLocation(NuevaPos);
}
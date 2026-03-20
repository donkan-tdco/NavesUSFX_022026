#include "EnemigoAcuatico.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

AEnemigoAcuatico::AEnemigoAcuatico() : AEnemigoBase()
{
    Velocidad = 200.0f;

    // Buscamos la Esfera básica de Unreal
    static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));

    if (SphereMesh.Succeeded())
    {
        MeshEnemigo->SetStaticMesh(SphereMesh.Object);
    }
}

void AEnemigoAcuatico::MoverEnemigo(float DeltaTime)
{
    float ZigZag = FMath::Sin(GetWorld()->GetTimeSeconds() * 3.0f);
    FVector NuevaPos = GetActorLocation() + (FVector(DirX, ZigZag, 0.0f) * Velocidad * DeltaTime);
    SetActorLocation(NuevaPos);
}
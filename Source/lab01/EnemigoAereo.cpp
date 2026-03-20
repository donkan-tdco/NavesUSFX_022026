#include "EnemigoAereo.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

AEnemigoAereo::AEnemigoAereo() : AEnemigoBase()
{
    Velocidad = 500.0f;

    // Buscamos el Cono básico de Unreal para que parezca un triángulo
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ConeMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'"));

    if (ConeMesh.Succeeded())
    {
        MeshEnemigo->SetStaticMesh(ConeMesh.Object);
        // Opcional: Ajustamos la escala si es muy pequeño
        MeshEnemigo->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
    }
}

void AEnemigoAereo::MoverEnemigo(float DeltaTime)
{
    Super::MoverEnemigo(DeltaTime);
}
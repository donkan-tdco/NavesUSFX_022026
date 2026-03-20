#include "EnemigoBase.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AEnemigoBase::AEnemigoBase()
{
    PrimaryActorTick.bCanEverTick = true;

    // Inicializamos la malla
    MeshEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshEnemigo"));
    RootComponent = MeshEnemigo;

    // ESTO CORRIGE LA BOLA BLANCA: Asigna un cubo por defecto para que lo veas
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
    if (CubeMesh.Succeeded())
    {
        MeshEnemigo->SetStaticMesh(CubeMesh.Object);
    }
}

void AEnemigoBase::BeginPlay()
{
    Super::BeginPlay();
    SetLifeSpan(8.0f); // Desaparecen en 8 segundos

    // Generamos el rumbo aleatorio UNA sola vez al nacer
    DirX = FMath::RandRange(-1.0f, 1.0f);
    DirY = FMath::RandRange(-1.0f, 1.0f);
}

void AEnemigoBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    MoverEnemigo(DeltaTime);
}

void AEnemigoBase::MoverEnemigo(float DeltaTime)
{
    // Movimiento base aleatorio en X e Y
    FVector NuevaPos = GetActorLocation() + (FVector(DirX, DirY, 0.0f) * Velocidad * DeltaTime);
    SetActorLocation(NuevaPos);
}
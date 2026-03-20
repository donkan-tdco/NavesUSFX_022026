// Copyright Epic Games, Inc. All Rights Reserved.

#include "lab01Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

Alab01Projectile::Alab01Projectile()
{
	// USAMOS UNA ESFERA BÁSICA DEL MOTOR PARA EVITAR EL ERROR
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));

	// Creamos el componente de malla
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh0"));

	if (ProjectileMeshAsset.Succeeded())
	{
		ProjectileMesh->SetStaticMesh(ProjectileMeshAsset.Object);
	}

	// Configuramos la raíz y colisión
	RootComponent = ProjectileMesh;
	ProjectileMesh->SetCollisionProfileName(TEXT("Projectile"));

	// Escala pequeña para que parezca una bala
	ProjectileMesh->SetRelativeScale3D(FVector(0.2f, 0.2f, 0.2f));

	// Configuración de la función al chocar
	ProjectileMesh->OnComponentHit.AddDynamic(this, &Alab01Projectile::OnHit);

	// Movimiento del proyectil
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement0"));
	ProjectileMovement->UpdatedComponent = ProjectileMesh;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.f; // Sin gravedad

	// Tiempo de vida de 3 segundos
	InitialLifeSpan = 3.0f;
}

void Alab01Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Si golpeamos algo con físicas, le damos un empujón
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation());
	}

	// Destruimos la bala al chocar
	Destroy();
}
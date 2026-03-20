#include "ETSoldado.h"

AETSoldado::AETSoldado()
{
	// Un soldado es un cubo flaco y alto
	if (MeshEnemigo)
	{
		MeshEnemigo->SetWorldScale3D(FVector(0.4f, 0.4f, 1.5f));
	}
}
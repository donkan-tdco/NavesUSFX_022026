#include "ETTanque.h"

AETTanque::AETTanque()
{
	// Un tanque es un cubo ancho, largo y aplastado
	if (MeshEnemigo)
	{
		MeshEnemigo->SetWorldScale3D(FVector(2.5f, 2.0f, 0.7f));
	}
}
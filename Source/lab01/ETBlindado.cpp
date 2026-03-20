#include "ETBlindado.h"

AETBlindado::AETBlindado()
{
	// Un blindado es un cubo robusto y cuadrado
	if (MeshEnemigo)
	{
		MeshEnemigo->SetWorldScale3D(FVector(2.0f, 2.0f, 1.2f));
	}
}
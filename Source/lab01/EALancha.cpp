#include "EALancha.h"

AEALancha::AEALancha()
{
	if (MeshEnemigo)
	{
		// Más corta que el barco y más pegada al "agua"
		MeshEnemigo->SetWorldScale3D(FVector(2.5f, 1.0f, 0.4f));
	}
}
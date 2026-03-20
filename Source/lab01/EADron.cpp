#include "EADron.h"

AEADron::AEADron()
{
	if (MeshEnemigo)
	{
		// El dron es una dona pequeñita
		MeshEnemigo->SetWorldScale3D(FVector(0.5f, 0.5f, 0.2f));
	}
}
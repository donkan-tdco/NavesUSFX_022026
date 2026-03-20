#include "EABarco.h"

AEABarco::AEABarco()
{
	if (MeshEnemigo)
	{
		// Una esfera muy estirada en X para que parezca un buque largo
		MeshEnemigo->SetWorldScale3D(FVector(5.0f, 1.5f, 0.8f));
	}
}
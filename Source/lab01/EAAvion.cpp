#include "EAAvion.h"

AEAAvion::AEAAvion()
{
	if (MeshEnemigo)
	{
		// El avión es una dona estirada hacia los lados (como alas) y muy plana
		MeshEnemigo->SetWorldScale3D(FVector(1.0f, 4.0f, 0.2f));
	}
}
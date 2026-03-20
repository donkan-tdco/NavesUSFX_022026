#include "ETCamion.h"

AETCamion::AETCamion()
{
	// Un camión es un cubo largo y alto
	if (MeshEnemigo)
	{
		MeshEnemigo->SetWorldScale3D(FVector(3.5f, 1.2f, 1.5f));
	}
}
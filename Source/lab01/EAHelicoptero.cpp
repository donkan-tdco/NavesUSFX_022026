#include "EAHelicoptero.h"

AEAHelicoptero::AEAHelicoptero()
{
	if (MeshEnemigo)
	{
		// El helicóptero es una dona grande y robusta
		MeshEnemigo->SetWorldScale3D(FVector(2.0f, 2.0f, 0.8f));
	}
}
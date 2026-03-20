#include "EAMotoAcuatica.h"

AEAMotoAcuatica::AEAMotoAcuatica()
{
	if (MeshEnemigo)
	{
		// Una esfera pequeña y ligeramente ovalada
		MeshEnemigo->SetWorldScale3D(FVector(1.0f, 0.5f, 0.5f));
	}
}
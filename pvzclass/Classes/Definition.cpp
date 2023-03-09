#include "../PVZ.h"

PVZ::PlantDefinition::PlantDefinition(int id)
{
	BaseAddress = 0x69F2B0 + 0x24 * id;
}

PVZ::ZombieDefinition::ZombieDefinition(int id)
{
	BaseAddress = 0x69DA80 + 0x1C * id;
}
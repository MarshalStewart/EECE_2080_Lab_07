#include "ShipFactory.h"

#include "BattleShip.h"
#include "Cruiser.h"


ShipFactory::ShipFactory()
{
	m_raceMap[ShipFactory::enumOfRace::ZergRace] = new Zerg();

}


Iship* ShipFactory::CreateShip(enumOfTypeShip enumOfTypeShipType, enumOfRace race)
{

	IRace * raceReference = m_raceMap[race];

	Iship* retVal = nullptr;
	if (enumOfTypeShipType == BattleShipType)
	{
		retVal = new BattleShip(raceReference);
	}
    else if (enumOfTypeShipType == CruiserType)
    {
        retVal = new Cruiser(raceReference);
    }

	return retVal;
}

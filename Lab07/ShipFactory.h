#pragma once

#include "IRace.h"
#include "Iship.h"
#include "Zerg.h"
#include <map>

class ShipFactory
{
public:


	enum enumOfTypeShip { BattleShipType, CruiserType };
	enum enumOfRace { ZergRace };

	ShipFactory();

	Iship* CreateShip(enumOfTypeShip typeOfShip, enumOfRace race);

    virtual ~ShipFactory() {}

private:

	std::map< enumOfRace, IRace*> m_raceMap;

};


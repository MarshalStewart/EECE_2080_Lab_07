#pragma once

#include "IRace.h"
#include "IShip.h"
#include <map>

#ifndef SHIPFACTORY
#define SHIPFACTORY

class ShipFactory
{
public:

	enum Ship_Type { STAR_DESTROYER, STAR_FIGHTER, STAR_BOMBER, 
							STAR_APACHEATTACKHELICOPTER };
	enum Race_Type { E_NAZI, E_SPQR, E_USA, E_USSR };

	ShipFactory();

	IShip* CreateShip(Ship_Type ship, Race_Type race);

    virtual ~ShipFactory() {}

private:

	std::map<Race_Type, IRace*> m_raceMap;

};


#endif //SHIPFACTORY		
	
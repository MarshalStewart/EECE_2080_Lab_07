#include "ShipFactory.h"
#include "IShip.h"
#include "IRace.h"

ShipFactory::ShipFactory()
{
	m_raceMap[ShipFactory::Race_Type::E_NAZI] = new NAZI();
	m_raceMap[ShipFactory::Race_Type::E_SPQR] = new SPQR();
	m_raceMap[ShipFactory::Race_Type::E_USA] = new USA();
	m_raceMap[ShipFactory::Race_Type::E_USSR] = new USSR();
}

IShip* ShipFactory::CreateShip(Ship_Type ship, Race_Type race)
{
	IRace * raceReference = m_raceMap[race];

	IShip* retVal = nullptr;
	
	switch(ship){
		case(Ship_Type::STAR_DESTROYER):
			return new Star_Destroyer(raceReference);

		case(Ship_Type::STAR_FIGHTER):
			return new Star_Fighter(raceReference);
			
		case(Ship_Type::STAR_BOMBER):
			return new Star_Bomber(raceReference);
			
		case(Ship_Type::STAR_APACHEATTACKHELICOPTER):
			return new Star_ApacheAttackHelicopter(raceReference);
			
		default:	
			// invalid selection
			return nullptr;
	}
}

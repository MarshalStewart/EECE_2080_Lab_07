// tests.cpp
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include "ShipFactory.cpp"
#include "IRace.h"
#include "IShip.h"
#include "Fleet.h"

using namespace std;


TEST(Fleet, shipInit)
{
	ShipFactory shipFactory;
	IShip* new_ship = shipFactory.CreateShip(
		ShipFactory::Ship_Type::STAR_DESTROYER, ShipFactory::Race_Type::E_NAZI);

	int atk = new_ship->GetNumAttacks();
	int hit = new_ship->GetHitBonus();
	int dmg = new_ship->GetDamageBonus();
	int hp = new_ship->GetHitPoints();
	int ac = new_ship->GetArmorClass();
	int init = new_ship->GetInitiativeBonus();

	ASSERT_EQ(atk, 1);
	ASSERT_EQ(hit, 0);
	ASSERT_EQ(dmg, 30);
	ASSERT_EQ(hp, 200);
	ASSERT_EQ(ac, 12);
	ASSERT_EQ(init, 0);


	new_ship = shipFactory.CreateShip(
		ShipFactory::Ship_Type::STAR_FIGHTER, ShipFactory::Race_Type::E_NAZI);

	atk = new_ship->GetNumAttacks();
	hit = new_ship->GetHitBonus();
	dmg = new_ship->GetDamageBonus();
	hp = new_ship->GetHitPoints();
	ac = new_ship->GetArmorClass();
	init = new_ship->GetInitiativeBonus();

	ASSERT_EQ(atk, 1);
	ASSERT_EQ(hit, 7);
	ASSERT_EQ(dmg, 10);
	ASSERT_EQ(hp, 20); 
	ASSERT_EQ(ac, 18);
	ASSERT_EQ(init, 6);


	new_ship = shipFactory.CreateShip(
		ShipFactory::Ship_Type::STAR_BOMBER, ShipFactory::Race_Type::E_NAZI);

	atk = new_ship->GetNumAttacks();
	hit = new_ship->GetHitBonus();
	dmg = new_ship->GetDamageBonus();
	hp = new_ship->GetHitPoints();
	ac = new_ship->GetArmorClass();
	init = new_ship->GetInitiativeBonus();

	ASSERT_EQ(atk, 1);
	ASSERT_EQ(hit, 4);
	ASSERT_EQ(dmg, 50);
	ASSERT_EQ(hp, 30); 
	ASSERT_EQ(ac, 14);
	ASSERT_EQ(init, 1);


	new_ship = shipFactory.CreateShip(
		ShipFactory::Ship_Type::STAR_APACHEATTACKHELICOPTER, ShipFactory::Race_Type::E_NAZI);

	atk = new_ship->GetNumAttacks();
	hit = new_ship->GetHitBonus();
	dmg = new_ship->GetDamageBonus();
	hp = new_ship->GetHitPoints();
	ac = new_ship->GetArmorClass();
	init = new_ship->GetInitiativeBonus();

	ASSERT_EQ(atk, 1);
	ASSERT_EQ(hit, 7);
	ASSERT_EQ(dmg, 30);
	ASSERT_EQ(hp, 20); 
	ASSERT_EQ(ac, 8); 
	ASSERT_EQ(init, 9);

}

TEST(Fleet, EmptyConstructor)
{
	ShipFactory shipFactory;
	IShip* new_ship1 = shipFactory.CreateShip(
		ShipFactory::Ship_Type::STAR_DESTROYER, ShipFactory::Race_Type::E_NAZI);

	IShip* new_ship2 = shipFactory.CreateShip(
		ShipFactory::Ship_Type::STAR_DESTROYER, ShipFactory::Race_Type::E_NAZI);

    Fleet<IShip*> *fleet = new Fleet<IShip*>();
	fleet->setFlagShip(new_ship1);
	fleet->addFlotilla(new_ship1);
	fleet->addFlotilla(new_ship2);
	vector<IShip*> v = fleet->getFlotilla();

	ASSERT_EQ(v.size(), 2);

	delete fleet;
}

TEST(Fleet, isEmpty1)
{

	ShipFactory shipFactory;
	IShip* new_ship = shipFactory.CreateShip(
		ShipFactory::Ship_Type::STAR_DESTROYER, ShipFactory::Race_Type::E_NAZI);
    
	Fleet<IShip*> *fleet;
	vector<IShip*> v = fleet->getFlotilla();

	ASSERT_EQ(v.size(), 0);

}

TEST(Fleet, addShip1)
{
	ShipFactory shipFactory;
	IShip* flag_ship = shipFactory.CreateShip(
		ShipFactory::Ship_Type::STAR_DESTROYER, ShipFactory::Race_Type::E_NAZI);

	IShip* new_ship = shipFactory.CreateShip(
		ShipFactory::Ship_Type::STAR_DESTROYER, ShipFactory::Race_Type::E_NAZI);

    Fleet<IShip*> *fleet = new Fleet<IShip*>(flag_ship);
	fleet->addFlotilla(new_ship);
	vector<IShip*> v = fleet->getFlotilla();

	ASSERT_EQ(v.size(), 1);
	ASSERT_EQ(v[0]->GetArmorClass(), 12);

	delete fleet;

}

TEST(Fleet, getShip)
{
	ShipFactory shipFactory;
	IShip* flag_ship = shipFactory.CreateShip(
		ShipFactory::Ship_Type::STAR_DESTROYER, ShipFactory::Race_Type::E_NAZI);

	IShip* new_ship = shipFactory.CreateShip(
		ShipFactory::Ship_Type::STAR_DESTROYER, ShipFactory::Race_Type::E_NAZI);
	
    Fleet<IShip*> *fleet = new Fleet<IShip*>(flag_ship);
	fleet->addFlotilla(new_ship);

	new_ship = shipFactory.CreateShip(
		ShipFactory::Ship_Type::STAR_FIGHTER, ShipFactory::Race_Type::E_NAZI);

	fleet->addFlotilla(new_ship);
	vector<IShip*> v = fleet->getFlotilla();

	ASSERT_EQ(v.size(), 2);
	ASSERT_EQ(v[0]->GetArmorClass(), 12);
	ASSERT_EQ(v[1]->GetArmorClass(), 18);

	IShip *cur_ship = fleet->getLeftFrontShip();
	ASSERT_EQ(cur_ship->GetArmorClass(), v[0]->GetArmorClass());

	cur_ship = fleet->getRightFrontShip();
	ASSERT_EQ(cur_ship->GetArmorClass(), v[1]->GetArmorClass());
	
	delete fleet;

}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

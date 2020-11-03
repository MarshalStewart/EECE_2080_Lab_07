#include "IRace.h"
#include <memory>

#ifndef ISHIP
#define ISHIP

using namespace std;

class IShip
{
public:

/*
General Structure Ship:
	number of attacks per turn
	bonus when trying (rolling) to attack
	bonus to damage on successful hit
	health
	armor (opponent needs to roll higher than this number to hit successfully)
	bonus to initiative (who attacks first in a given round)
*/
	IShip() {};
	IShip(IRace* race) { m_race = race; }
	IShip(IRace* race, int na, int hb, int db, int hp, int ac, int ib) : 
		m_race(race), m_Num_Attacks(na), m_Hit_Bonus(hb), m_Damage_Bonus(db), 
		m_Hit_Points(hp), m_Armor_Class(ac), m_Initiative_Bonus(ib) {}

	~IShip() {delete m_race;}

	IRace *GetRace() {return m_race; }
	int GetNumAttacks() { return m_Num_Attacks; };	
	int GetHitBonus() { return m_Hit_Bonus; }
	int GetDamageBonus() { return m_Damage_Bonus; }
	int GetHitPoints() { return m_Hit_Points; }
	int GetArmorClass() { return m_Armor_Class; }
	int GetInitiativeBonus() {return m_Initiative_Bonus; }

	void SetNumAttacks(int na) { m_Num_Attacks = na; };	
	void SetHitBonus(int hb) { m_Hit_Bonus = hb; }
	void SetDamageBonus(int db) { m_Damage_Bonus = db; }
	void SetHitPoints(int hp) { m_Hit_Points = hp; }
	void SetArmorClass(int ac) { m_Armor_Class = ac; }
	void SetInitiativeBonus(int ib) { m_Initiative_Bonus = ib; }


protected:
	int m_Num_Attacks; // number of attacks per turn
	int m_Hit_Bonus; // to hit bonus
	int m_Damage_Bonus; // damage bonus
	int m_Hit_Points; // health
	int m_Armor_Class; // armor class
	int m_Initiative_Bonus; // initiative bonus
	
	IRace* m_race;

};


class Star_Destroyer : public IShip
{
public:

	Star_Destroyer(IRace* race) : 
	IShip(race, 1, 0, 30, 200, 12, 0)
	{
		// int m_Num_Attacks = 1;
		// int m_Hit_Bonus = 0; // low
		// int m_Damage_Bonus = 30; // high
		// int m_Hit_Points = 200; // high 
		// int m_Armor_Class = 12; // med
		// int m_Initiative_Bonus = 0; // lo
	}

    ~Star_Destroyer() { delete m_race; }  

private :
    Star_Destroyer();

};

class Star_Fighter : public IShip
{
public:

	Star_Fighter(IRace* race) : 
	IShip(race, 1, 7, 10, 20, 18, 6)
	{
		// m_race = race;

		// int m_Num_Attacks = 1;
		// int m_Hit_Bonus = 7; // high
		// int m_Damage_Bonus = 10; // low-med
		// int m_Hit_Points = 20; // low
		// int m_Armor_Class = 18; // high
		// int m_Initiative_Bonus = 6; // med-high
	}
    
	~Star_Fighter() { delete m_race; }

private :
    Star_Fighter();

};

class Star_Bomber : public IShip
{
public:

	Star_Bomber(IRace* race) :
	IShip(race, 1, 4, 50, 30, 14, 1)
	{
		// m_race = race;

		// int m_Num_Attacks = 1;
		// int m_Hit_Bonus = 4; // med-high
		// int m_Damage_Bonus = 50; // high
		// int m_Hit_Points = 30; // low
		// int m_Armor_Class = 14; // med-high
		// int m_Initiative_Bonus = 1; // low
	}

	~Star_Bomber() { delete m_race; }

private :
    Star_Bomber();

};

class Star_ApacheAttackHelicopter : public IShip
{
public:

	Star_ApacheAttackHelicopter(IRace* race) :
	IShip(race, 1, 7, 30, 20, 8, 9)
	{
		// m_race = race;

		// int m_Num_Attacks = 1;
		// int m_Hit_Bonus = 7; // high
		// int m_Damage_Bonus = 30; // high
		// int m_Hit_Points = 20; // low
		// int m_Armor_Class = 8; // low
		// int m_Initiative_Bonus = 9; // high
	}

    ~Star_ApacheAttackHelicopter() { delete m_race; }
	

private :
    Star_ApacheAttackHelicopter();

};

#endif // ISHIP
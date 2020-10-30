#pragma once
#include "../Races/IRace.h"

#ifndef ISHIP
#define ISHIP

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
    IShip(IRace* race)
	{
		m_race = race;

		int m_Num_Attacks = 0;
		int m_Hit_Bonus = 0;
		int m_Damage_Bonus = 0;
		int m_Hit_Points = 0;
		int m_Armor_Class = 0;
		int m_Initiative_Bonus = 0;
    }

	virtual int GetNumAttacks();	
	virtual int GetHitBonus();
	virtual int GetDamageBonus();
	virtual int GetHitPoints();
	virtual int GetArmorClass();
	virtual int GetInitiativeBonus();

    virtual ~IShip() {}

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

	Star_Destroyer(IRace* race) : IShip(race)
	{
		m_race = race;

		int m_Num_Attacks = 0;
		int m_Hit_Bonus = 0; // low-med
		int m_Damage_Bonus = 0; // high
		int m_Hit_Points = 0; // high
		int m_Armor_Class = 0; // low-med
		int m_Initiative_Bonus = 0; // low
	}

	int GetNumAttacks() { return m_Num_Attacks; };	
	int GetHitBonus() { return m_Hit_Bonus; }
	int GetDamageBonus() { return m_Damage_Bonus; }
	int GetHitPoints() { return m_Hit_Points; }
	int GetArmorClass() { return m_Armor_Class; }
	int GetInitiativeBonus() {return m_Initiative_Bonus; }


    ~Star_Destroyer() {}

private :
    Star_Destroyer();

};

class Star_Fighter : public IShip
{
public:

	Star_Fighter(IRace* race) : IShip(race)
	{
		m_race = race;

		int m_Num_Attacks = 0;
		int m_Hit_Bonus = 0; // high
		int m_Damage_Bonus = 0; // low-med
		int m_Hit_Points = 0; // low
		int m_Armor_Class = 0; // high
		int m_Initiative_Bonus = 0; // med-high
	}

	int GetNumAttacks() { return m_Num_Attacks; };	
	int GetHitBonus() { return m_Hit_Bonus; }
	int GetDamageBonus() { return m_Damage_Bonus; }
	int GetHitPoints() { return m_Hit_Points; }
	int GetArmorClass() { return m_Armor_Class; }
	int GetInitiativeBonus() {return m_Initiative_Bonus; }

    ~Star_Fighter() {}

private :
    Star_Fighter();

};

class Star_Bomber : public IShip
{
public:

	Star_Bomber(IRace* race) : IShip(race)
	{
		m_race = race;

		int m_Num_Attacks = 0;
		int m_Hit_Bonus = 0; // 
		int m_Damage_Bonus = 0;
		int m_Hit_Points = 0;
		int m_Armor_Class = 0;
		int m_Initiative_Bonus = 0;
	}

	int GetNumAttacks() { return m_Num_Attacks; };	
	int GetHitBonus() { return m_Hit_Bonus; }
	int GetDamageBonus() { return m_Damage_Bonus; }
	int GetHitPoints() { return m_Hit_Points; }
	int GetArmorClass() { return m_Armor_Class; }
	int GetInitiativeBonus() {return m_Initiative_Bonus; }    ~Star_Bomber() {}

private :
    Star_Bomber();

};

class Star_ApacheAttackHelicopter : public IShip
{
public:

	Star_ApacheAttackHelicopter(IRace* race) : IShip(race)
	{
		m_race = race;

		int m_Num_Attacks = 0;
		int m_Hit_Bonus = 0; // 
		int m_Damage_Bonus = 0;
		int m_Hit_Points = 0;
		int m_Armor_Class = 0;
		int m_Initiative_Bonus = 0;
	}

	int GetNumAttacks() { return m_Num_Attacks; };	
	int GetHitBonus() { return m_Hit_Bonus; }
	int GetDamageBonus() { return m_Damage_Bonus; }
	int GetHitPoints() { return m_Hit_Points; }
	int GetArmorClass() { return m_Armor_Class; }
	int GetInitiativeBonus() {return m_Initiative_Bonus; }

    ~Star_ApacheAttackHelicopter() {}

private :
    Star_ApacheAttackHelicopter();

};

#endif // ISHIP
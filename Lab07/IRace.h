#ifndef IRACE
#define IRACE

class IRace
{
public:
	IRace() {}
	IRace(int hp, int ac, int hit, int initiative) : 
		m_Hit_Point_Mod(hp), m_Armor_Class_Mod(ac), m_Hit_Bonus_Mod(hit),
		m_Initiative_Bonus_Mod(initiative) {}

	int GetHitPointModification() { return m_Hit_Point_Mod; }
	int GetArmorClassModification() { return m_Armor_Class_Mod; }
	int GetHitBonusModification() { return m_Hit_Bonus_Mod; } 
	int GetInitiativeBonus() { return m_Initiative_Bonus_Mod; }

protected:
	int m_Hit_Point_Mod;
	int m_Armor_Class_Mod;
	int m_Hit_Bonus_Mod;
	int m_Initiative_Bonus_Mod;

};

// Nazi Socialist Workers Party
/*
	Blitzkrieg: Take hit bonus penalty to get damage bonus on successful hit

	less likely to hit but hit harder

	ah thats cool, probably can do a rand num 1-10 and then if it's > 1 then attack (this happens everytime?)

	what buff do u want?  -3 hitbonus for +15 damagebonus (balance is hard)

*/
class NAZI : public IRace
{
public:
	NAZI() : IRace(0, 0, 0, 0)
	{
	}
	
};

// Senatus Populusque Romanus
/*
	High Ground Flanking: Can attack back-row
*/
class SPQR : public IRace
{
public:
	SPQR() : IRace(0, 0, 0, 0)
	{
	}
	
};

// United States of America Space Force
/*
	Tactical Communism Prevention: 10% chance to drop a nuke for massive area of effect damage
*/
class USA : public IRace
{
public:
	USA() : IRace(0, 0, 0, 0)
	{
	}

};


// Union of Soviet Socialist Republics
/*
	Scorched Earth: Damage buff, but attacks do recoil damage
*/
class USSR : public IRace
{
public:
	USSR() : IRace(0, 0, 0, 0) 
	{
	}

};

#endif // IRACE

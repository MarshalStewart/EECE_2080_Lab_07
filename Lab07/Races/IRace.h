#pragma once

#ifndef IRACE
#define IRACE

class IRace
{
public:
	IRace(int Hit_Points, int Armor_Class, int Hit_Bonus)
	{
		// m_Hit_Points = Hit_Points;
		// m_Armor_Class = Armor_Class;
		// m_Hit_Bonus = Hit_Bonus;
	}
   	~IRace() {}

	virtual void HitPointMOdification();
	virtual void ArmorClassModification();
	virtual void HitBonusModification();
	virtual void InitiativeBonus();

	// virtual int GetHitPoints() { return m_Hit_Points; }
	// virtual int GetArmorClass() { return m_Armor_Class; }
	// virtual int GetHitBonus() { return m_Hit_Bonus; }
	virtual int GetNAZIMult() { return m_NAZI_Mult; }
	virtual int GetSPQRMult() { return m_SPQR_Mult; }
	virtual int GetUSAMult() { return m_USA_Mult; }
	virtual int GetUSSRMult() { return m_USSR_Mult; }

protected:
	// int m_Hit_Points;
	// int m_Armor_Class;
	// int m_Hit_Bonus;
	int m_NAZI_Mult;
	int m_SPQR_Mult;
	int m_USA_Mult;
	int m_USSR_Mult;

};

// Nazi Socialist Workers Party
/*
	Blitzkrieg: Big initiative bonus for Nazi ship
*/
class NAZI : public IRace
{
public:
	NAZI(int Hit_Points, int Armor_Class, int Hit_Bonus)
	{
		m_NAZI_Mult = 0;
		m_SPQR_Mult = 0;
		m_USA_Mult = 0;
		m_USSR_Mult = 0;
	}

	void HitPointMOdification() override;
	void ArmorClassModification() override;
	void HitBonusModification() override;
	void InitiativeBonus() override;
	
	int GetNAZIMult() override { return m_NAZI_Mult; }
	int GetSPQRMult() override { return m_SPQR_Mult; }
	int GetUSAMult() override { return m_USA_Mult; }
	int GetUSSRMult() override { return m_USSR_Mult; }

};

// Senatus Populusque Romanus
/*
	High Ground: Gives all allies Armor Buff
*/
class SPQR : IRace
{
public:
	SPQR(int Hit_Points, int Armor_Class, int Hit_Bonus)
	{
		m_Hit_Points = Hit_Points;
		m_Armor_Class = Armor_Class;
		m_Hit_Bonus = Hit_Bonus;
	
		m_NAZI_Mult = 0;
		m_SPQR_Mult = 0;
		m_USA_Mult = 0;
		m_USSR_Mult = 0;
	}

	void HitPointMOdification() override;
	void ArmorClassModification() override;
	void HitBonusModification() override;
	void InitiativeBonus() override;
	
	int GetHitPoints() override { return m_Hit_Points; }
	int GetArmorClass() override { return m_Armor_Class; }
	int GetHitBonus() override { return m_Hit_Bonus; }
	int GetNAZIMult() override { return m_NAZI_Mult; }
	int GetSPQRMult() override { return m_SPQR_Mult; }
	int GetUSAMult() override { return m_USA_Mult; }
	int GetUSSRMult() override { return m_USSR_Mult; }
};

// United States of America Space Force
/*
	Tactical Communism Prevention: 10% chance to drop a nuke for massive aoe damage
*/
class USA : IRace
{
public:
	USA(int Hit_Points, int Armor_Class, int Hit_Bonus)
	{
		m_Hit_Points = Hit_Points;
		m_Armor_Class = Armor_Class;
		m_Hit_Bonus = Hit_Bonus;
	
		m_NAZI_Mult = 0;
		m_SPQR_Mult = 0;
		m_USA_Mult = 0;
		m_USSR_Mult = 0;
	}

	void HitPointMOdification() override;
	void ArmorClassModification() override;
	void HitBonusModification() override;
	void InitiativeBonus() override;
	
	int GetHitPoints() override { return m_Hit_Points; }
	int GetArmorClass() override { return m_Armor_Class; }
	int GetHitBonus() override { return m_Hit_Bonus; }
	int GetNAZIMult() override { return m_NAZI_Mult; }
	int GetSPQRMult() override { return m_SPQR_Mult; }
	int GetUSAMult() override { return m_USA_Mult; }
	int GetUSSRMult() override { return m_USSR_Mult; }
};


// Union of Soviet Socialist Republics
/*
	Scorched Earth: Damage buff, but attacks do recoil damage
*/
class USSR : IRace
{
public:
	USSR(int Hit_Points, int Armor_Class, int Hit_Bonus)
	{
		m_Hit_Points = Hit_Points;
		m_Armor_Class = Armor_Class;
		m_Hit_Bonus = Hit_Bonus;
	
		m_NAZI_Mult = 0;
		m_SPQR_Mult = 0;
		m_USA_Mult = 0;
		m_USSR_Mult = 0;
	}

	void HitPointMOdification() override;
	void ArmorClassModification() override;
	void HitBonusModification() override;
	void InitiativeBonus() override;
	
	int GetHitPoints() override { return m_Hit_Points; }
	int GetArmorClass() override { return m_Armor_Class; }
	int GetHitBonus() override { return m_Hit_Bonus; }
	int GetNAZIMult() override { return m_NAZI_Mult; }
	int GetSPQRMult() override { return m_SPQR_Mult; }
	int GetUSAMult() override { return m_USA_Mult; }
	int GetUSSRMult() override { return m_USSR_Mult; }
};

#endif // IRACE

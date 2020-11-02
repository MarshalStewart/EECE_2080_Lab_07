#ifndef IRACE
#define IRACE

class IRace
{
public:
	IRace() {}
	IRace(int nazi_m, int spqr_m, int usa_m, int ussr_m) : 
		m_NAZI_Mult(nazi_m), m_SPQR_Mult(spqr_m), m_USA_Mult(usa_m),
		m_USSR_Mult(ussr_m) {}

	virtual void HitPointModification() = 0; //TODO
	virtual void ArmorClassModification() = 0; //TODO
	virtual void HitBonusModification() = 0; // TODO
	virtual void InitiativeBonus() = 0; // TODO

	int GetNAZIMult() { return m_NAZI_Mult; }
	int GetSPQRMult() { return m_SPQR_Mult; }
	int GetUSAMult() { return m_USA_Mult; }
	int GetUSSRMult() { return m_USSR_Mult; }

protected:
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
	NAZI() : IRace(0, 0, 0, 0)
	{
		// m_NAZI_Mult = 0;
		// m_SPQR_Mult = 0;
		// m_USA_Mult = 0;
		// m_USSR_Mult = 0;
	}
	
	void HitPointModification() override {}
	void ArmorClassModification() override {}
	void HitBonusModification() override {}
	void InitiativeBonus() override {}
	
};

// Senatus Populusque Romanus
/*
	High Ground: Gives all allies Armor Buff
*/
class SPQR : public IRace
{
public:
	SPQR() : IRace(0, 0, 0, 0)
	{
		// m_NAZI_Mult = 0;
		// m_SPQR_Mult = 0;
		// m_USA_Mult = 0;
		// m_USSR_Mult = 0;
	}

	void HitPointModification() override {}
	void ArmorClassModification() override {}
	void HitBonusModification() override {}
	void InitiativeBonus() override {}
	
};

// United States of America Space Force
/*
	Tactical Communism Prevention: 10% chance to drop a nuke for massive aoe damage
*/
class USA : public IRace
{
public:
	USA() : IRace(0, 0, 0, 0)
	{
		// m_NAZI_Mult = 0;
		// m_SPQR_Mult = 0;
		// m_USA_Mult = 0;
		// m_USSR_Mult = 0;
	}

	void HitPointModification() override {}
	void ArmorClassModification() override {}
	void HitBonusModification() override {}
	void InitiativeBonus() override {}
	
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
		// m_NAZI_Mult = 0;
		// m_SPQR_Mult = 0;
		// m_USA_Mult = 0;
		// m_USSR_Mult = 0;
	}

	void HitPointModification() override {}
	void ArmorClassModification() override {}
	void HitBonusModification() override {}
	void InitiativeBonus() override {}
	
};

#endif // IRACE

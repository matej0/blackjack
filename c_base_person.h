#pragma once
#include "includes.h"

enum Actions
{
	NONE = -1,
	STAND = 1,
	HIT = 2, 
	DOUBLEDOWN = 3,
};

enum Result
{
	NOTHING = -1,
	WIN = 1,
	BUST = 2,
	DRAW = 3,
};

class CBasePerson
{
public:
	int GenerateCard();
	void GenerateHand();

	int GetAction() { return m_iAction; };
	void SetAction(int value) { m_iAction = value; };

	bool GetIsDealer() { return m_bIsDealer; };
	void SetIsDealer(bool value) { m_bIsDealer = value; };

	int GetHand() { return m_iHand; };
	void SetHand(int value) { m_iHand = value; };

	int GetResult() { return m_iResult; };
	void SetResult(int value) { m_iResult = value; };

	void Check();
	std::deque<int> GetCards;
private:
	int  m_iAction = NONE;
	int  m_iHand = 0;
	int  m_iResult = NOTHING;
	bool m_bIsDealer;
	
};
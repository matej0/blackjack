#pragma once
#include "c_base_person.h"
#include "c_base_player.h"

class CBaseDealer : public CBasePerson
{
public:

	CBaseDealer()
	{
		this->SetIsDealer(true);
	};

	void CheckPenis(CBasePlayer& player);
	void Play(CBasePlayer& player);
private:
};
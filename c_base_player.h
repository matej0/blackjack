#pragma once
#include "c_base_person.h"

class CBasePlayer : public CBasePerson
{
public:

	CBasePlayer()
	{
		this->SetIsDealer(false);
	};

	void Parse();
	void Play();
private:

};
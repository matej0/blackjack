#include "c_base_player.h"



void CBasePlayer::Parse()
{
	std::string strInput;
	std::cin >> strInput;

	if (strInput == "h")
		this->SetAction(HIT);
	else if (strInput == "s")
		this->SetAction(STAND);
	else if (strInput == "dd")
		this->SetAction(DOUBLEDOWN);
	else
		this->SetAction(NONE);
}

void CBasePlayer::Play()
{
	if (this->GetResult() == BUST)
		return;

	if (this->GetAction() == STAND)
		return;

	switch (this->GetAction())
	{
	case HIT:
	{
		int iNewCard = this->GenerateCard();
		this->GetCards.push_front(iNewCard);
		this->SetHand(this->GetHand() + iNewCard);
		this->Check();
		std::cout << "New hand: " << this->GetHand() << std::endl;
	} break;
	case DOUBLEDOWN:
	{
		this->SetAction(STAND);
		int iNewCard = this->GenerateCard();
		this->GetCards.push_front(iNewCard);
		this->SetHand(this->GetHand() + iNewCard);
		this->Check();
		std::cout << "New hand: " << this->GetHand() << std::endl;
	} break;
	}
}
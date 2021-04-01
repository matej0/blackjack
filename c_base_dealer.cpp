#include "c_base_dealer.h"

void CBaseDealer::CheckDealer(CBasePlayer& player) //CBasePeepee
{
	int nHand = this->GetHand();

	if (nHand > 21)
		player.SetResult(WIN);
	else if (nHand == 21)
		player.SetResult(BUST);
}

void CBaseDealer::Play(CBasePlayer& player)
{
	if (player.GetResult() == WIN || player.GetResult() == BUST)
		return;

	if (player.GetAction() != STAND || this->GetAction() == STAND)
		return;

	if (this->GetHand() > 16)
	{
		this->SetAction(STAND);
		return;
	}

	int iNewCard = this->GenerateCard();
	this->GetCards.push_front(iNewCard);
	this->SetHand(this->GetHand() + iNewCard);
	this->CheckDealer(player);
	printf("New dealer hand: %i\n", this->GetHand());
}

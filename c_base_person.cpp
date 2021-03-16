#include "c_base_person.h"
#include "utilities.h"

void CBasePerson::Check()
{
	int nHand = this->GetHand();

	if (nHand > 21)
		this->SetResult(BUST);
	else if (nHand == 21)
		this->SetResult(WIN);
	else
		this->SetResult(NOTHING);
}

int CBasePerson::GenerateCard()
{
	int iCard = Utils::Random(1, 10);

	if (this->GetHand() < 11 && iCard == 1)
		iCard = 11;

	return iCard;
}

void CBasePerson::GenerateHand()
{
	int iHand = 0, iCard = 0;

	for (int i = 0; i < 2; i++)
	{
		iCard = this->GenerateCard();

		this->GetCards.push_front(iCard);

		iHand += iCard;

		this->SetHand(iHand);
	}

	if (this->GetIsDealer())
		std::cout << "Dealer hand: " << this->GetHand() << std::endl;
	else
		std::cout << "Hand: " << this->GetHand() << std::endl;
}


#include "includes.h"
#include "c_base_player.h"
#include "c_base_dealer.h"
#pragma warning(disable: 4244)

//you need to pass CBasePlayer as reference otherwise m_iResult isnt getting set.
void Compare(CBasePlayer& player, CBaseDealer dealer)
{
	if (player.GetAction() == STAND && dealer.GetAction() == STAND)
	{
		int nPlayerHand = player.GetHand();
		int nDealerHand = dealer.GetHand();

		//jesus fucking christ
		if (nPlayerHand > nDealerHand && nPlayerHand <= 21)
		{
			player.SetResult(WIN);
		}
		else if (nDealerHand > nPlayerHand && nDealerHand <= 21)
		{
			player.SetResult(BUST);
		}
		else if (nPlayerHand == nDealerHand && nDealerHand <= 21 && nPlayerHand <= 21)
		{
			player.SetResult(DRAW);
		}
		else
		{
			player.SetResult(WIN);
		}
	}
}

int main()
{
	CBasePlayer player;
	CBaseDealer dealer;
	dealer.GenerateHand();
	player.GenerateHand();

	while (true)
	{
		if (player.GetResult() == BUST)
		{
			std::cout << "You busted!\n";
			break;
		}

		if (player.GetResult() == WIN)
		{
			std::cout << "You Won!\n";
			break;
		}

		if (player.GetResult() == DRAW)
		{
			std::cout << "It's a tie!\n";
			break;
		}

		if (player.GetAction() != STAND)
		{
			std::cout << "h = Hit, s = Stand, dd = Double down\n";
			player.Parse();
		}
		
		player.Play();
		dealer.Play(player);
		Compare(player, dealer);
	}

	system("pause");
}
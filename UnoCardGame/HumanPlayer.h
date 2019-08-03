#pragma once
#include "Player.h"
class HumanPlayer :
	public player
{
public:
  void play(card &played_card, deck &main_deck, deck &temp_deck, player *play_array[] = NULL);
};


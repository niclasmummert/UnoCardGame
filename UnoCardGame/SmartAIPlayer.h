#pragma once
#include "Player.h"
#include "Deck.h"

class SmartAIPlayer :
	public player
{
public:
	void play(card &played_card, deck &main_deck, deck &temp_deck, SmartAIPlayer *play_array);
};


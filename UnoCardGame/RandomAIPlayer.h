#pragma once
#include "Player.h"
#include "Deck.h"

class RandomAIPlayer:
	public player
{
public:
	void play(card &played_card, deck &main_deck, deck &temp_deck, RandomAIPlayer *play_array);
};


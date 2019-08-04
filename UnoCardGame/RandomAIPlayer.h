#pragma once
#include "Player.h"
#include "Deck.h"
#include "Card.h"

class RandomAIPlayer:
	public player
{
public:
	virtual void play(card &played_card, deck &main_deck, deck &temp_deck, RandomAIPlayer play_array);
	RandomAIPlayer();
};


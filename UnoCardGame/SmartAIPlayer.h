#pragma once
#include "Player.h"
#include "Deck.h"
#include "Card.h"

class SmartAIPlayer :
	public player
{
public:
	virtual void play(card &played_card, deck &main_deck, deck &temp_deck, SmartAIPlayer play_array);
	SmartAIPlayer();
};


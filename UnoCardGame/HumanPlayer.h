#pragma once
#include "Player.h"
#include "Deck.h"
#include "Card.h"

class HumanPlayer :
	public player
{
public:
  virtual void play(card &played_card, deck &main_deck, deck &temp_deck, HumanPlayer play_array) override;
  HumanPlayer();
};


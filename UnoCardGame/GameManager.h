#pragma once
#ifndef GAMEMANAGER_H_
#include "Card.h"
#include "Deck.h"
#include "Player.h"

#include <iostream>
#include <string>


class GameManager: public deck, player
{
public:
	void displayIntro();
};

#endif // !GAMEMANAGER_H_
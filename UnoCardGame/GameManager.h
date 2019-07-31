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
	//void game(bool);


	
};

#endif // !GAMEMANAGER_H_
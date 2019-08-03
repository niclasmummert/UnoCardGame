#pragma once
#ifndef GAMEMANAGER_H_
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "RandomAIPlayer.h"
#include"SmartAIPlayer.h"

#include <iostream>
#include <string>



class GameManager: public deck, HumanPlayer, SmartAIPlayer, RandomAIPlayer 
{
public:
	void displayIntro();
	//static bool force_draw_bool = false;
	
	//player(const player & other);
	//const player & operator=(const player & other);
	//~player();
	//void hand_add(card temp);
	//card hand_remove(int pos);
	//void uno();
	//void print() const;
	//int get_size() const;
	//card peek(int pos) const;
};

#endif // !GAMEMANAGER_H_
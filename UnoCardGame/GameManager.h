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
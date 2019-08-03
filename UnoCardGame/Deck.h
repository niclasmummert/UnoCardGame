#pragma once
#ifndef Deck_H_
#define DECK_H_
#include "Card.h"



class deck: public card
{
public:
	deck();
	deck(const deck & other);
	const deck & operator=(const deck & other);
	~deck();
	void shuffle();
	card draw();
	void create();
	int add_card(card temp_card);
	void print_deck();
	int get_size();

private:
	card * ptr_deck;
	int size;
	void clear();
	void copy(const deck & other);
};

std::ostream & operator<<(std::ostream & out, deck const & temp_deck);

#endif // !Deck_H_
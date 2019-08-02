#pragma once
#ifndef PLAYER_H_
#include "Card.h"


class player
{
public:
	//virtual void play(card &played_card, deck &main_deck, deck &temp_deck, player *play_array[]) = 0;
	//wird nicht funktionieren wegen Konstruktor!?
	player();
	//virtual player() = 0;  -> eventuell initialisierung mit anderem Namen damit != Konstruktor + deklaration in Card? -> !!override!! -> braucht Typ?
	//wird nicht funktionieren wegen Konstruktor!?
	//TO-DO wegen copy(other)
	player(const player & other);
	//virtual player(const player & other) = 0; -> eventuell initialisierung mit anderem Namen damit != Konstruktor + deklaration in Card?
	const player & operator=(const player & other);
	~player();
	void hand_add(card temp);
	card hand_remove(int pos);
	void uno();
	void print() const;
	int get_size() const;
	card peek(int pos) const;

protected:
	
	class card_elem
	{
	public:
		card_elem()
		{
			next = NULL;
		};
		card data;
		card_elem * next;
	};

	card_elem * head;
	int size;
	void copy(const player & other);
	void clear();
};

#endif // !PLAYER_H_

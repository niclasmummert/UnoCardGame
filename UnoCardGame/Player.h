#pragma once
#ifndef PLAYER_H_
#include "Card.h"
#include "Deck.h"

//auf Handhabung achten!!!

class player
{
public:
	virtual void play(card &played_card, deck &main_deck, deck &temp_deck, player *play_array) = 0;
	//wird nicht funktionieren wegen Konstruktor!?
	//player();
	//virtual player() = 0;  -> eventuell initialisierung mit anderem Namen damit != Konstruktor + deklaration in Card? -> !!override!! -> braucht Typ?
	//wird nicht funktionieren wegen Konstruktor!?
	//TO-DO wegen copy(other)
	void copy(const player & other);
	//virtual player(const player & other) = 0; -> eventuell initialisierung mit anderem Namen damit != Konstruktor + deklaration in Card?
	const player & operator=(const player & other);
	~player();
	void hand_add(card temp);
	card hand_remove(int pos);
	void uno();
	void print() const;
	int get_size() const;
	card peek(int pos) const;
	bool force_draw_bool = false;
	unsigned int Random_AI_win = 0;
	unsigned int Smart_AI_win = 0;
	unsigned int turn = 0;
	Color FromString(const std::string & str, int x = 6);
	bool win = false;

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
	//void copy(const player & other);
	void clear();
};

#endif // !PLAYER_H_

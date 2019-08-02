#pragma once
#ifndef PLAYER_H_
#include "Card.h"


class player
{
public:
	player();
	//virtual player() = 0;  -> eventuell initialisierung mit anderem Namen damit != Konstruktor + deklaration in Card? -> !!override!! -> braucht Typ?
	player(const player & other);
	//virtual player(const player & other) = 0; -> eventuell initialisierung mit anderem Namen damit != Konstruktor + deklaration in Card?
	const player & operator=(const player & other);
	//virtual const player & operator=(const player & other) = 0;
	~player();
	//virtual ~player() = 0;
	void hand_add(card temp);
	//virtual void hand_add(card temp) = 0;
	card hand_remove(int pos);
	// virtual card hand_remove(int pos) = 0;
	void uno();
	//virtual void uno() = 0;
	void print() const;
	//virtual void print() const = 0;
	int get_size() const;
	//virtual int get_size() const = 0;
	card peek(int pos) const;
	//virtual card peek(int pos) const = 0;

private:
	
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

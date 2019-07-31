#include "Deck.h"
#include "Card.h"
#include <iostream>

#define DECK_SIZE 108



deck::deck()
{
	ptr_deck = new card[DECK_SIZE];
	size = 0;
}

deck::deck(const deck & other)
{
	copy(other);
}

const deck & deck::operator=(const deck & other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}


deck::~deck()
{
	clear();
}

void deck::shuffle()
{
	card * temp_deck = new card[size];

	for (int i = 0; i < size; i++)
	{
		temp_deck[i] = ptr_deck[i];
	}

	int temp_size = size;
	int temp_pos;
	int pos;

	for (int i = 0; i < size; i++)
	{
		std::srand(time_t(NULL));
		pos = std::rand() % temp_size;
		ptr_deck[i] = temp_deck[pos];

		temp_size--;
		for (temp_pos = pos; temp_pos < temp_size; temp_pos++)
		{
			temp_deck[temp_pos] = temp_deck[temp_pos + 1];
		}
	}

	delete[] temp_deck;
}

card deck::draw()
{
	if (size <= 0)
	{
		return card();
	}
	card temp_card = ptr_deck[size - 1];
	size--;
	return temp_card;
}

void deck::create()
{
	int num = 0;

	for (int col = 1; col <= 4; col++)
	{
		ptr_deck[size].number = num;
		ptr_deck[size].color = static_cast<Color>(col);
		size++;
	}

	for (num = 1; num <= 12; num++)
	{
		for (int x = 0; x < 2; x++)
		{
			for (int col = 1; col <= 4 ; col++)
			{
				ptr_deck[size].number = num;
				ptr_deck[size].color = static_cast<Color>(col);
				size++;
			}
		}
	}

	for ( num = 13; num <=14 ; num++)
	{
		for (int x = 0; x < 4; x++)
		{
			ptr_deck[size].number = num;
			ptr_deck[size].color = wild;
			size++;
		}
	}
}

int deck::add_card(card temp_card)
{
	if (size < DECK_SIZE)
	{
		ptr_deck[size] = temp_card;
		size++;
		return 0;
	}
	else return -1;
}

void deck::print_deck()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i << ": " << ptr_deck[i] << std::endl;
	}
}

int deck::get_size()
{
	return size;
}

void deck::clear()
{
	delete[] ptr_deck;
	ptr_deck = NULL;
	size = 0;
}

void deck::copy(const deck & other)
{
	size = other.size;
	ptr_deck = new card[size];
	for (int i = 0; i < size; i++)
	{
		ptr_deck[i] = other.ptr_deck[i];
	}
}

//std::ostream & operator<<(std::ostream & out, deck const & temp_deck)
//{
//	if (this!= &other)
//	{
//		clear();
//		copy(other);
//	}
//	return *this;
//}


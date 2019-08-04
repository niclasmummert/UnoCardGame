#pragma once
#include "Player.h"
#include "Card.h"
#include <iostream>

//player::player()
//{
//	head = NULL;
//	size = 0;
//}

//player::player(const player & other)
//{
//	copy(other);
//}

const player & player::operator=(const player & other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}

player::~player()
{
	clear();
}

card player::hand_remove(int pos)
{
	if (pos < 0 || pos >= size)
	{
		return card();
	}

	card_elem * prev_ptr = head;
	card_elem * target = prev_ptr->next;
	card temp_card;
	int temp_pos = pos;

	if (pos == 0)
	{
		temp_card = head->data;
		head = head->next;
		delete prev_ptr;
		size--;
		return temp_card;
	}
	
	while (temp_pos>1)
	{
		prev_ptr = prev_ptr->next;
		target = prev_ptr->next;
		temp_pos--;
	}

	prev_ptr->next = target->next;
	temp_card = target->data;
	delete target;
	size--;
	return temp_card;
}

//definition auswärts
void player::hand_add(card temp_card)
{
	card_elem * temp_ptr;
	temp_ptr = new card_elem();
	temp_ptr->data = temp_card;
	temp_ptr->next = head;
	head = temp_ptr;
	size++;
}

//definition auswärts
void player::uno()
{
	std::cout << "'UNO' !!! "<<std::endl;
}

void player::print() const
{
	int temp_size = size;
	int i = 0;
	card_elem * temp_ptr = head;
	while (temp_size> 0)
	{
		std::cout << i << ":  " << temp_ptr->data << std::endl;
		temp_ptr = temp_ptr->next;
		i++;
		temp_size--;
	}
}

int player::get_size() const
{
	return size;
}

card player::peek(int pos) const
{
	int temp_pos = pos;
	card_elem * temp_elem = head;
	while (temp_pos >0)
	{
		temp_elem = temp_elem->next;
		temp_pos--;
	}
	return temp_elem->data;
}

//Function for generating a color
Color player::FromString(const std::string & str, int x)
{
	if (x == 6)
	{
		if (str == "red")
		{
			return red;
		}
		else if (str == "green")
		{
			return green;
		}
		else if (str == "blue")
		{
			return blue;
		}
		else if (str == "yellow")
		{
			return yellow;
		}
		else return wild;
	}
	else if (str == "zero")
	{
		if (x == 1)
		{
			return red;
		}
		else if (x == 2)
		{
			return green;
		}
		else if (x == 3)
		{
			return blue;
		}
		else if (x == 4)
		{
			return yellow;
		}
		else return wild;
	}
	else return wild;
}

void player::play(card & played_card, deck & main_deck, deck & temp_deck, player play_array)
{
}

void player::copy(const player & other)
{
	size = other.size;

	if (size>0)
	{
		head = new card_elem();
		head->data = other.head->data;
	}
	else
	{
		head = NULL;
		return;
	}

	card_elem * other_ptr = other.head->next;
	card_elem * temp_ptr;
	card_elem * prev_ptr = head;

	for (int i = 1; i < size; i++)
	{
		temp_ptr = new card_elem();
		prev_ptr->next = temp_ptr;
		temp_ptr->data = other_ptr->data;
		prev_ptr = temp_ptr;
		temp_ptr = NULL;
		other_ptr = other_ptr->next;
	}
}

void player::clear()
{
	card_elem * temp_ptr = head;
	card_elem * next_ptr;
	while (size>0)
	{
		next_ptr = temp_ptr->next;
		delete temp_ptr;
		temp_ptr = next_ptr;
		size--;
	}
	head = NULL;
}


#pragma once
#ifndef _Card_H_
#define _Card_H_
#include <ostream>
#include <string>

enum Color
{
	wild, red, green, blue, yellow
};



class card
{
public:
	int number; //0-9 numbers for each color, +2 in every color, skip in every color, reverse in every color, all color, +4 (all color)
	Color color; //5 colors: red, green, blue, yellow, and no color(wild)

	bool operator==(card const & other) const;
	bool operator!=(card const & other) const;

	card(int number, Color col);
	card();
	~card();
};

std::ostream & operator<<(std::ostream & out, card const & temp_card);

#endif // !_Card_H_

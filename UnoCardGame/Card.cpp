#include "Card.h"
#include <string>

card::card()
{
	number = 0;
	color = wild;
}

bool card::operator==(card const & other) const
{
	return number == other.number || color == other.color || color == wild || other.color == wild;
}

bool card::operator!=(card const & other) const
{
	return !(*this == other);
}

card::card(int num, Color col)
{
	number = num;
	color = col;
}


card::~card()
{
}

std::ostream & operator<<(std::ostream & out, card const & temp_card)
{
	out << "Number: ";

	switch (temp_card.number)
	{
	case 10: out << "DRAW -2"; 
		break;
	case 11: out << "SKIP"; 
		break;
	case 12: out << "REVERSE"; 
		break;
	case 13: out << "WILD"; 
		break;
	case 14: out << "DRAW -4 WILD"; 
		break;
	default: out << (int)temp_card.number; 
		break;
	}

	out << "   Color:";

	switch (temp_card.color)
	{
	case wild: out << "wild"; 
		break;
	case red: out << "red"; 
		break;
	case yellow: out << "yellow"; 
		break;
	case green: out << "green"; 
		break;
	case blue: out << "blue"; 
		break;
	default: out << "not available"; 
		break;
	}
	return out;
}


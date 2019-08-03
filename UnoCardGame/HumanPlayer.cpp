#include "HumanPlayer.h"
#include "GameManager.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"

#include <iostream>
#include <string>
#include <stdlib.h>

void HumanPlayer::play(card &played_card, deck &main_deck, deck &temp_deck, player *play_array[] = NULL)
{
	//player *curr_player = play_array[1];
	HumanPlayer curr_player = play_array[1];
	//std::system("CLS");

		//checking the played_card if player have to pick up card
	if (force_draw_bool)
	{
		//picking up 2 cards
		if (played_card.number == 10)
		{
			std::cout << "Forced Draw +2" << std::endl;
			card draw_2;
			for (int i = 0; i < 2; i++)
			{
				draw_2 = main_deck.draw();
				curr_player->hand_add(draw_2);
			}
		}
		//picking up 4 cards
		else if (played_card.number == 14)
		{
			std::cout << "Forced Draw +4" << std::endl;
			card draw_4;
			for (int i = 0; i < 4; i++)
			{
				draw_4 = main_deck.draw();
				curr_player->hand_add(draw_4);
			}
		}
		force_draw_bool = false;
	}

	std::cout << "Number of Cards remaining: " << std::endl;
	std::cout << curr_player->get_size() << std::endl;

	std::cout << "Played Card: " << played_card << std::endl;
	curr_player->print();

	int check_flag = 0;
	int index = 0;
	int size = curr_player->get_size();

	//Human Player's turn
	while (check_flag == 0)
	{
		std::cout << "Which card do you want to play" << std::endl;
		std::cout << "If you want to draw a card please enter '-1'" << std::endl;
		std::cout << "Or type the index of the card and press enter:" << std::endl;
		std::cin >> index;

		//draw a card
		if (index == -1)
		{
			card draw_temp;
			draw_temp = main_deck.draw();
			std::cout << "DRAWN CARD: " << draw_temp << std::endl;

			if (draw_temp == played_card && draw_temp.color != wild)
			{
				int play_draw_flag = 0;

				while (play_draw_flag == 0)
				{
					std::string temp_play;
					std::cout << "Do you want to play the draw card? Please type 'y' for yes or 'n' for no!" << std::endl;
					std::cin >> temp_play;

					//playing the drawn card
					if (temp_play == "y")
					{
						played_card = draw_temp;
						temp_deck.add_card(draw_temp);
						if (played_card.number >= 10 && played_card.number <= 14)
						{
							force_draw_bool = true;
						}
						play_draw_flag = 1;
					}
					//picking up the drawn card
					else if (temp_play == "n")
					{
						curr_player->hand_add(draw_temp);
						play_draw_flag = 1;
					}
				}
			}
			//Human Player has to pick up the card
			else
			{
				curr_player->hand_add(draw_temp);
			}
			check_flag = 1;
		}

		//playing a card of the handdeck
		if (index >= 0 && index < size)
		{
			card temp = curr_player->peek(index);
			if (temp == played_card)
			{
				curr_player->hand_remove(index);
				temp_deck.add_card(temp);
				played_card = temp;

				//choosing a color for next round
				if (played_card.color == wild)
				{
					int check_color = 0;
					Color temp_color;
					std::string str_color;

					while (check_color == 0)
					{
						std::cout << "Please choose a color(red, green, blue, yellow) :";
						std::cin >> str_color;
						temp_color = FromString(str_color);

						if (temp_color != wild)
						{
							played_card.color = temp_color;
							check_color = 1;
						}
						//not allowed to pick color: wild
						else
						{
							std::cout << "invalid color" << std::endl;
						}
					}
				}
				//playing card is a  +2 or WILD+4
				if (played_card.number == 10 || played_card.number == 14)
				{
					force_draw_bool = true;
				}
				//checking if played card is SKIP or REVERSE
				else if ((played_card.number == 11 || played_card.number == 12) && force_draw_bool == true)
				{
					turn += 2;
				}
				check_flag = 1;
			}
			else
			{
				std::cout << "Card cannot be played" << std::endl;
			}
		}

		else
		{
			std::cout << "Invalid index " << std::endl;
		}
	}

	//Player calls "UNO!"
	if (curr_player->get_size() == 1)
	{
		curr_player->uno();
	}
	//Human-Player won
	else if (curr_player->get_size() == 0)
	{
		win = true;
		std::cout << "You have won the game!" << std::endl;
		std::cout << "Thank you for playing the game!" << std::endl;
	}
	//Number of Cards left in the handdeck
	else
	{
		std::cout << "Remaining cards: " << curr_player->get_size() << std::endl;
		std::cout << std::endl;
		std::cout << "These are: " << curr_player->print() << std::endl;
	}
	std::cout << "Played card: " << played_card << std::endl;
}


#include "SmartAIPlayer.h"
#include "GameManager.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"

#include <iostream>
#include <string>
#include <stdlib.h>

void SmartAIPlayer::play(card & played_card, deck & main_deck, deck & temp_deck, SmartAIPlayer play_array)
{
		int index = 0;
		bool firstround = true;
		SmartAIPlayer *curr_player = &play_array;
		//->SmartAIPlayer *curr_player = &SmartAIPlayer -> wenn nicht funktioniert, funktioniert überladene Operator nicht
		int size = curr_player->get_size();

		//checking the played_card if player have to pick up card	
		if (force_draw_bool)
		{	
			//picking up 2 cards
			if (played_card.number == 10)
			{
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
				card draw_4;
				for (int i = 0; i < 4; i++)
				{
					draw_4 = main_deck.draw();
					curr_player->hand_add(draw_4);
				}
			}
			force_draw_bool = false;
		}

		card temp_card_mock;
		//playing a card in the first round
		while (firstround)
		{
			//choosing a random color, but beginning with a SKIP
			static bool force_draw_bool = false;
			std::srand(time_t(NULL));
			int coincidence = rand() % 4 + 1;
			Color temp_color = curr_player->FromString("zero", coincidence);
			temp_card_mock.color = temp_color;
			temp_card_mock.number = 11;
			firstround = false;
		}
		//If opponent plays a WILD Card, Smart-AI-Players plays automaticly a WILD +4
		if (played_card.color == wild)
		{
			temp_card_mock.color = wild;
			temp_card_mock.number = 14;
		}
		//If opponent plays a +2, Smart-AI-Player also plays a +2
		else if (played_card.number == 10)
		{
			temp_card_mock.number = 10;
			std::srand(time_t(NULL));
			int coincidence = rand() % 4 + 1;
			Color temp_color = curr_player->FromString("zero", coincidence);
			temp_card_mock.color = temp_color;
		}
		//If opponent plays a +4, Smart-AI-Player also plays a +4
		else if (played_card.number == 14)
		{
			temp_card_mock.color = wild;
			temp_card_mock.number = 14;
		}
		//If opponent plays a card, Smart-AI-Player plays same color of card, but increased number
		else
		{
			temp_card_mock.number = played_card.number + 1;
			temp_card_mock.color = played_card.color;
		}

		played_card = temp_card_mock;
		temp_deck.add_card(played_card);
		size--;
		//checking if playing card is WILD card
		if (played_card.color == wild)
		{
			int check_color = 0;
			Color temp_color;

			while (check_color == 0)
			{
				//random color
				std::srand(time_t(NULL));
				int coincidence = rand() % 4 + 1;
				temp_color = curr_player->FromString("zero", coincidence);

				if (temp_color != wild)
				{
					played_card.color = temp_color;
					check_color = 1;
					std::cout << "Smart-AI-Player choose the color:" << temp_color << std::endl;
				}
				else
				{
					std::cout << "Smart-AI invalid color" << std::endl;
				}
			}
		}

		if (size == 1)
		{
			std::cout << "Smart-AI-Player calls "; 
			curr_player->uno();
		}
		else if (size == 0)
		{
			std::cout << "Smart-AI-PLAYER has won the game!" << std::endl;
			std::cout << "Thank you for playing the game!" << std::endl;
			Smart_AI_win++;
			win = true;
		}
		//REVERSE or SKIP card
		if ((played_card.number == 11 || played_card.number == 12) && force_draw_bool == true)
		{
			turn += 2;
		}
		else
		{
			turn += 1;
		}

		std::system("CLS");
		std::cout << "Played card: " << played_card << std::endl;
		//checking if playing card is +2 or +4
		if (played_card.number == 10 || played_card.number == 14)
		{
			force_draw_bool = true;
		}
		//informing the opponent that he misses a round 
		else if (played_card.number == 11 || played_card.number == 12)
		{
			std::cout << "The Smart-AI-Player let you skip this round" << std::endl;
		}
		index += 1;
}

SmartAIPlayer::SmartAIPlayer()
{
}


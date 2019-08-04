#include "RandomAIPlayer.h"
#include "GameManager.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"

#include <iostream>
#include <string>
#include <stdlib.h>


void RandomAIPlayer::play(card & played_card, deck & main_deck, deck & temp_deck, RandomAIPlayer play_array)
{
	{		
		RandomAIPlayer *curr_player = &play_array;
			card *playing_card = &played_card;
		
			//checking the played_card if player have to pick up card
			if (force_draw_bool)
			{
				//picking up 2 cards
				if (playing_card->number == 10)
				{
					card draw_2;
					for (int i = 0; i < 2; i++)
					{
						draw_2 = main_deck.draw();
						curr_player->hand_add(draw_2);
					}
				}
		
				//picking up 4 cards
				if (playing_card->number == 14)
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

			static bool force_draw_bool = false;
			int check_flag = 0;
			int size = curr_player->get_size();
		
			while (check_flag == 0)
			{
				//iterating through handdeck if a card is playable
				int index = 0;
				for (index; index <= size; index++)
				{
					card temp = curr_player->peek(index);
					//checking if card is playable
					if (&temp == playing_card)
					{
						curr_player->hand_remove(index);
						temp_deck.add_card(temp);
						playing_card = &temp;
						//choosing random color
						if (playing_card->color == wild)
						{
							int check_color = 0;
							Color temp_color;
		
							while (check_color == 0)
							{
								std::srand(time_t(NULL));
								int coincidence = rand() % 4 + 1;
								temp_color = curr_player->FromString("zero", coincidence);
		
								if (temp_color != wild)
								{
									playing_card->color = temp_color;
									check_color = 1;
									std::cout << "AI-Player choose the color:" << temp_color << std::endl;
								}
								else
								{
									std::cout << "AI invalid color" << std::endl;
								}
							}
						}
						//if a card is playable, leaving the clauses
						check_flag = 1;
						break;
					}
				}
				//pick up a card
				if (index > size)
				{
					curr_player->hand_add(main_deck.draw());
				}
		
				if (size == 1)
				{
					std::cout << "AI-Player calls "; 
					curr_player->uno();
				}
				else if (size == 0)
				{
					std::cout << "AI-PLAYER has won the game!" << std::endl;
					std::cout << "Thank you for playing the game!" << std::endl;
					Random_AI_win++;
					win = true;
				}
		
				if ((playing_card->number == 11 || playing_card->number == 12) && force_draw_bool == true)
				{
					turn += 2;
				}
		
				std::system("CLS");
				std::cout << "Played card: " << playing_card << std::endl;
				//checking if playing card is +2 or +4
				if (playing_card->number == 10 || playing_card->number == 14)
				{
					force_draw_bool = true;
				}
				//informing opponent that he misses a round
				else if (playing_card->number == 11 || playing_card->number == 12)
				{
					std::cout << "The AI-Player let you skip this round" << std::endl;
				}
				turn += 1;
			}
		
		}
}

RandomAIPlayer::RandomAIPlayer()
{
}

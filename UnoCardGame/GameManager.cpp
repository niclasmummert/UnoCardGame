#include "GameManager.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"

#include <iostream>
#include <string>
#include <stdlib.h>

bool AI_Value = false;
bool testing = false;
unsigned int turn = 0;
bool win = false;
bool force_draw_bool = false;

void AI_Player(card, deck, deck, player[]);
void Smart_AI_Player(card, deck, deck, player[]);
void human_Player(card, deck, deck, player[]);
void game(bool,bool);


//int calculate_turn(bool x)
//{
//	if (AI_Value == true)
//	{
//		turn = 1;
//	}
//	else
//	{
//		turn = 0;
//	}
//	return turn;
//}



void GameManager::displayIntro()
{
	std::cout << "Welcome to the ultimative UNO Card Game" << std::endl;
	std::cout << "What you wanna do?" << std::endl;
	std::cout << "Type 1 to read the rules" << std::endl;
	std::cout << "Type 2 to play against an AI opponent" << std::endl;
	std::cout << "Type 3 to play against a very good AI opponent" << std::endl;
	std::cout << "Type 4 for the testing" << std::endl;
	std::cout << "Type 5 for ending the UNO card game" << std::endl;

	int i = 0;

	std::cin >> i;

	switch (i)
	{
		//Rules
	case 1: std::cout << "Playing a card that matches  the discard in color, number or symbol" << std::endl;
			std::cout << "Playing a wild card, or a playable wild draw Four card" << std::endl;
			std::cout << "Draw the top card from the deck, then play if it is possible" << std::endl;
			std::cout << "A player who draws from the deck must either play or keep that card and may play no other card from their hand on that turn" << std::endl;
			std::cout << "It is illegal to trade cards of any sort with another player" << std::endl;
			std::cout << "A player who plays their 'next-to-last-card' must call 'UNO'" << std::endl;
			std::cout << "The first player to get rid of their last card wins the game" << std::endl;
		
			std::cout << "UNO card game consists of 108 Cards; SKIP stands for 'Next player in sequence misses a turn'" << std::endl;
			std::cout << "Reverse stands for 'Order of play switches directions', in our case it is equal to SKIP" << std::endl;
			std::cout << "Draw +2 stands for 'Next player in sequence draws two cards and misses a turn'" << std::endl;
			std::cout << "Wild stands for 'Players declare the next color to be matched'" << std::endl;
			std::cout << "Wild Draw +4 stands for 'Player declares the next color to be matched and next player in sequence draws four cards and misses a turn'" << std::endl;
			break;

		//Play against AI-Player
	case 2: {bool AI_Value = false;
		bool testing = false;
		game(AI_Value);
		break; }

		//Play against Smart-AI-Player
	case 3:   AI_Value = true;
		bool testing = false;
		game(AI_Value);
		break;

		//some testing //TO-DO
	case 4:  AI_Value = false;
		bool testing = true;
		break;

		//End Game
	case 5:  AI_Value = false;
		break;
	
	default:
		 AI_Value = false;
		std::cout << "not available" << std::endl;
		break;
	}

}

//Function for generating a color
Color FromString(const std::string & str, int x = 6)
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
		if ( x == 1)
		{
			return red;
		}
		else if ( x == 2)
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

//initializing the basics like desks, player and cards. Calling the players depending on who is playing aigainst whom
void game(bool Smart_AI_Value, bool testing = false)
{
	int amount_players = 2;
	std::system("CLS");
	
	//initializing two players
	player * play_array;
	player * curr_player = &play_array[2];

	//initializing deck
	deck spezialdeck;
	deck *main_deck = &spezialdeck;
	spezialdeck.create();
	spezialdeck.shuffle();

	int flag = 0;
	////play_array = new player[amount_players];

	//initializing danddeck of each player
	for (int i = 0; i < amount_players; i++)
	{

		for (int k = 0; k < 7; k++)
		{
			card temp_card;
			temp_card = spezialdeck.draw();
			play_array[i].hand_add(temp_card);
		}
	}

	bool turn_flag = true;
	while (turn_flag == true)
	{
		if (Smart_AI_Value == false)
		{
			player *Normal_AI = &play_array[0];
			player *Human_Player = &play_array[1];
		}
		else
		{
			player *Smart_AI = &play_array[0];
			player *Human_Player = &play_array[1];
		}
		turn_flag = false;
	}

	//initializing the playing card
	card cardd;
	card *played_card = &cardd;
	card temp_card;
	temp_card = spezialdeck.draw();
	deck temp_deck;


	//check if first card is permitted
	bool firstcard = true;
	while (firstcard == true)
	{
		if (temp_card.color != wild)
		{
			played_card = &temp_card;
			firstcard = false;
		}
		else
		{
			temp_deck.add_card(temp_card);
		}
	}


	// calling the player-Functions depending on which opponent you choose
	if (Smart_AI_Value == true)
	{
		while (win != true)
		{

			//Smart_AI_Player against human_Player
			for (turn = 0; turn < 1000; turn++)
			{
				if (turn % 2 == 0)
				{
					Smart_AI_Player(*played_card, *main_deck, deck temp_deck, player play_array[0]);
				}
				else
				{
					human_Player(*played_card, *main_deck, deck temp_deck, player play_array[1]);
				}
			}
		}
	}
	else if(Smart_AI_Value == false)
	{
		while (win != true)
		{

			//AI_Player against human_Player
			for (turn = 0; turn < 1000; turn++)
			{
				if (turn % 2 == 0)
				{
					AI_Player(* played_card, *main_deck, deck temp_deck, player play_array[0]);
				}
				else
				{
					human_Player(* played_card, *main_deck, deck temp_deck, player play_array[1]);
				}
			}
		}
	}
	else if (testing == true)
	{
		while (win != true)
		{

			//Smart_AI_Player against AI_Player for testing
			for (turn = 0; turn < 1000; turn++)
			{
				if (turn % 2 == 0)
				{
					Smart_AI_Player(* played_card, *main_deck, deck temp_deck, player play_array[0]);
				}
				else
				{
					AI_Player(* played_card, *main_deck, deck temp_deck, player play_array[1]);
				}
			}
		}
	}
}

	//-----------------------------------------------------------------------------------------------------------------------------------------------------------------//
	//-----------------------------------------------------------------------------------------------------------------------------------------------------------------//


void human_Player(card &played_card, deck &main_deck, deck temp_deck, player play_array[])
	{
			player *curr_player = &play_array[1];
			std::system("CLS");

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
				int index;
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
				}
				std::cout << "Played card: " << played_card << std::endl;
}
	
	//funktionsaufruf SmartAI
	void Smart_AI_Player(card &played_card, deck &main_deck, deck temp_deck, player play_array[])
	{
	
	int index = 0;
	bool firstround = true;
	player *curr_player = &play_array[0];
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
			std::srand(time_t(NULL));
			int coincidence = rand() % 4 + 1;
			Color temp_color = FromString("zero", coincidence);
			temp_card_mock.color = temp_color;
			temp_card_mock.number = 11;
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
			Color temp_color = FromString("zero", coincidence);
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
				temp_color = FromString("zero", coincidence);

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
			std::cout << "Smart-AI-Player calls "; curr_player->uno();
		}
		else if (size == 0)
		{
			std::cout << "Smart-AI-PLAYER has won the game!" << std::endl;
			std::cout << "Thank you for playing the game!" << std::endl;
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

	//Funktionsaufruf Normaler-AI-Player
	void AI_Player(card &played_card, deck &main_deck, deck temp_deck, player play_array[])
	{	
		

			player *curr_player = &play_array[0];

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
				if (played_card.number == 14)
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
						if (temp == played_card)
						{
							curr_player->hand_remove(index);
							temp_deck.add_card(temp);
							played_card = temp;
							//choosing random color
							if (played_card.color == wild)
							{
								int check_color = 0;
								Color temp_color;

								while (check_color == 0)
								{
									std::srand(time_t(NULL));
									int coincidence = rand() % 4 + 1;
									temp_color = FromString("zero", coincidence);

									if (temp_color != wild)
									{
										played_card.color = temp_color;
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
					std::cout << "AI-Player calls "; curr_player->uno();
				}
				else if (size == 0)
				{
					std::cout << "AI-PLAYER has won the game!" << std::endl;
					std::cout << "Thank you for playing the game!" << std::endl;
				}

				if ((played_card.number == 11 || played_card.number == 12) && force_draw_bool == true)
				{
					turn += 2;
				}

				std::system("CLS");
				std::cout << "Played card: " << played_card << std::endl;
				//checking if playing card is +2 or +4
				if (played_card.number == 10 || played_card.number == 14)
				{
					force_draw_bool = true;
				}
				//informing opponent that he misses a round
				else if (played_card.number == 11 || played_card.number == 12)
				{
					std::cout << "The AI-Player let you skip this round" << std::endl;
				}
				turn += 1;
			}
		
	}






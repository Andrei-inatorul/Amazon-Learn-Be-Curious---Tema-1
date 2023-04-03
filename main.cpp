
#include <iostream>
#include "cardgame.h"
#include <fstream>

using std::cout;
using std::cin;


int main()
{
	DRAW_INTERFACE();
	char inputCommand[25];
	DECKS decks;
	decks.last = 0;
	decks.deckNumber = 0;
	while (true)
	{
		bool bad = true; //if input is invalid bad is true;
		while (bad == true)
		{
			cin >> inputCommand;
			bad = false;
			//maybe i could be more efficient here but i don t have much time so...
			if (strcmp("ADD_CARDS", inputCommand) == 0 || strcmp("add_cards", inputCommand) == 0)
			{
				int deckNo, cardNo;
				cin >> deckNo;
				cin >> cardNo;
				ADD_CARDS(decks, deckNo, cardNo);
			}
			else if (strcmp("ADD_DECK", inputCommand) == 0 || strcmp("add_deck", inputCommand) == 0)
			{
				int cardNo;
				cin >> cardNo;
				ADD_DECK(decks, cardNo);
			}
			else if (strcmp("DECK_NUMBER", inputCommand) == 0 || strcmp("deck_number", inputCommand) == 0)
			{
				DECK_NUMBER(decks);
			}
			else if (strcmp("DECK_LEN", inputCommand) == 0 || strcmp("deck_len", inputCommand) == 0)
			{
				int deckNo;
				cin >> deckNo;
				DECK_LEN(decks, deckNo);
			}
			else if (strcmp("DEL_CARD", inputCommand) == 0 || strcmp("del_card", inputCommand) == 0)
			{
				int deckNo, cardNo;
				cin >> deckNo;
				cin >> cardNo;
				DEL_CARD(decks, deckNo, cardNo);
			}
			else if (strcmp("DEL_DECK", inputCommand) == 0 || strcmp("del_deck", inputCommand) == 0)
			{
				int deckNo;
				cin >> deckNo;
				DEL_DECK(decks, deckNo);
			}
			else if (strcmp("EXIT", inputCommand) == 0 || strcmp("exit", inputCommand) == 0)
			{
				cout << "QUITIING GAME...\n";
				FREE_MEM(decks);
				return 0;
			}
			else if (strcmp("HELP", inputCommand) == 0 || strcmp("help", inputCommand) == 0)
			{
				DRAW_INTERFACE();
			}
			else if (strcmp("MERGE_DECKS", inputCommand) == 0 || strcmp("merge_decks", inputCommand) == 0)
			{
				int deckNo1, deckNo2;
				cin >> deckNo1 >> deckNo2;
				MERGE_DECKS(decks, deckNo1, deckNo2);
			}
			else if (strcmp("REVERSE_DECK", inputCommand) == 0 || strcmp("reverse_deck", inputCommand) == 0)
			{
				int deckNo;
				cin >> deckNo;
				REVERSE_DECK(decks, deckNo);
			}
			else if (strcmp("SHUFFLE_DECK", inputCommand) == 0 || strcmp("shuffle_deck", inputCommand) == 0)
			{
				int deckNo;
				cin >> deckNo;
				SHUFFLE_DECK(decks, deckNo);
				cout << "DECK SHUFFLED\n";
			}
			else if (strcmp("SHOW_ALL", inputCommand) == 0 || strcmp("show_all", inputCommand) == 0)
			{
				SHOW_ALL(decks);
			}
			else if (strcmp("SHOW_DECK", inputCommand) == 0 || strcmp("show_deck", inputCommand) == 0)
			{
				int deckNo;
				cin >> deckNo;
				SHOW_DECK(decks, deckNo);
			}
			else if (strcmp("SPLIT_DECK", inputCommand) == 0 || strcmp("split_deck", inputCommand) == 0)
			{
				int deckNo, splitIndex;
				cin >> deckNo >> splitIndex;
				SPLIT_DECK(decks, deckNo, splitIndex);
			}
			else if (strcmp("SORT_DECK", inputCommand) == 0 || strcmp("sort_deck", inputCommand) == 0)
			{
				cout << "WORK IN PROGRESS..\n";
			}
			else
			{
				cout << "Invalid command. Please try again.\n";
				bad = true;
			}
		}
	}
	return 0;
}
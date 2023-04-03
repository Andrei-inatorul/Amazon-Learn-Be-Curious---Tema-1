#include <iostream>
#include "cardgame.h"

using std::cin;
using std::cout;
using namespace std;


void DRAW_INTERFACE(void)
{
	//ascii art from 
	//https://ascii.co.uk/art/spades
	cout << "----------------- # ------------------------------------------------------------------------\n";
	cout << "---------------- ##= ------------------------------ Lefter Andrei --------------------------\n";
	cout << "--------------- ##=== ------------------ andrei.lefter@student.tuiasi.ro -------------------\n";
	cout << "------------- ###==#=== --------------------------------------------------------------------\n";
	cout << "----------- ####===##==== ------------------------------------------------------------------\n";
	cout << "--------- #####====###===== ------            Learn & Be Curious - Tema 1        -----------\n";
	cout << "-------- #####=====####===== -----              Grupa 1108A anul 1 CTI           -----------\n";
	cout <<	"-------- #####=====####===== -----                 Prepare to play!              -----------\n";
	cout << "---------- ####=  #  #==== -----------------------------------------------------------------\n";
	cout << "---------------- ##= -----------------------------------------------------------------------\n";
	cout << "-------------- ####=== ---------------------------------------------------------------------\n";
	int i;
	cout << "+";
	for (i = 1; i <= 90; ++i)
	{
		cout << "-";
	}
	cout << "+\n";
	cout << "|";
	printf("%54s", "Available Commands");
	printf("%38s", "|\n");
	cout << "+";
	for (i = 1; i <= 90; ++i)
	{
		cout << "-";
	}
	cout << "+\n";
	cout << "|";
	printf("%58s", "WARNING: DECKS ARE INDEXED FROM 1!");
	printf("%34s", "|\n");
	cout << "|";
	printf("%43s", "ADD_DECK <numberOfCards>");
	printf("%43s", "DEL_DECK <deckNo>");
	printf("%6s", "|\n");
	cout << "|";
	printf("%43s", "ADD_CARDS <deckIndex> <cardNo>");
	printf("%43s", "DEL_CARD <deckNo> <cardNo>");
	printf("%6s", "|\n");
	cout << "|";
	printf("%43s", "DECK_NUMBER");
	printf("%43s", "DECK_LEN <deckIndex>");
	printf("%6s", "|\n");
	cout << "|";
	printf("%43s", "SHUFFLE_DECK <deckIndex>");
	printf("%43s", "MERGE_DECKS <deckIndex1> <deckIndex2>");
	printf("%6s", "|\n");
	cout << "|";
	printf("%43s", "SPLIT_DECK <deckIndex> <splitIndex>");
	printf("%43s", "REVERSE_DECK <deckIndex>");
	printf("%6s", "|\n");
	cout << "|";
	printf("%43s", "SHOW_DECK <deckIndex>");
	printf("%43s", "SHOW_ALL");
	printf("%6s", "|\n");
	cout << "|";
	printf("%43s", "SORT_DECK <index_pachet>");
	printf("%43s", "EXIT");
	printf("%6s", "|\n");
	cout << "|";
	printf("%58s", "HELP - SHOWS THIS MENU AGAIN");
	printf("%34s", "|\n");
	cout << "+";
	for (i = 1; i <= 90; ++i)
	{
		cout << "-";
	}
	cout << "+";
	cout << "\n";
}

void ADD_DECK(DECKS &decks,int cardNo)
{
	/*
	*	Inputs: decks.lastDeck - adresa ultimului pachet
	*			cardNo - numarul de carti de adaugat in pachet
	*/
	decks.deckNumber++;
	DECK *nou = new DECK;
	if (decks.last == 0)
	{
		decks.first = nou;
		decks.first ->prev = 0;
		decks.first ->next = 0;
		decks.last = decks.first;
	}
	else
	{
		decks.last->next = nou;
		decks.last->next->prev = decks.last;
		decks.last = decks.last->next;
		decks.last->next = 0;
	}
	decks.last->cardNumber = cardNo;
	int index = 1;
	bool firstCardInDeck = true;
	char simbolCarte[7];
	int numarCarte;
	
	while (index <= cardNo)
	{
		CARD* carte = new CARD;
		cout << "Please enter card number: ";
		cin >> numarCarte;
		while(numarCarte > 14 || numarCarte < 1)
		{
			cout << "ERROR:INVALID CARD NUMBER\n\tPLEASE RE-ENTER CARD NUMBER: ";
			cin >> numarCarte;
		}
		cout << "Please enter card symbol: ";
		cin >> simbolCarte;
		while (strcmp("TREFLA", simbolCarte) && strcmp("CARO", simbolCarte) && strcmp("PICA", simbolCarte) &&  strcmp("CUPA", simbolCarte))
		{
			cout << "ERROR:INVALID CARD SYMBOL.MAKE SURE CARD SYMBOL IS ONE OF THE FOLLOWING (PICA, CUPA, CARO, TREFLA)\n\tPLEASE RE-ENTER CARD SYMBOL: ";
			cin >> simbolCarte;
		}
 		carte->number = numarCarte;
		strcpy_s(carte->symbol, simbolCarte);
		if (firstCardInDeck == true)
		{
			decks.last->lastCard = carte;
			decks.last->card = carte;
			decks.last->card->prev = 0;
			decks.last->card->next = 0;
			firstCardInDeck = false;
		}
		else
		{
			decks.last->lastCard->next = carte;
			decks.last->lastCard->next->prev = decks.last->lastCard;
			decks.last->lastCard = decks.last->lastCard->next;
		}
		index++;
	}
	decks.last->lastCard->next = 0;
	cout << "DECK ADDED SUCCESSFULLY\n";
}

void DEL_DECK(DECKS &decks, int deckNo)
{
	int index = 1;
	if (decks.deckNumber < deckNo || deckNo < 1)
	{
		cout << "The provided index is out of bounds for the deck list.\n";
		return;
	}
	decks.deckNumber--;
	DECK* currentDeck = decks.first;
	while (index < deckNo)
	{
		currentDeck = currentDeck->next;
		index++;
	}
	index = 1;
	CARD* currentCard = currentDeck->lastCard;
	while (currentCard != NULL)
	{
		CARD* AUX = currentCard;
		currentCard = currentCard->prev;
		delete AUX;
	}
	currentDeck->card = 0;
	currentDeck->cardNumber = 0;
	if (decks.first == decks.last)		// only one deck
	{
		decks.first = 0;
		decks.last = 0;
		delete currentDeck;
		currentDeck = 0;
	}
	else if (currentDeck->prev == NULL)		//first deck
	{
		currentDeck = currentDeck->next;
		decks.first = currentDeck;
		delete currentDeck->prev;
		currentDeck->prev = 0;
	}
	else if (currentDeck->next == NULL)		//last deck
	{
		currentDeck = currentDeck->prev;
		delete currentDeck->next;
		currentDeck->next = 0;
		decks.last = currentDeck;
	}
	else
	{
		DECK* AUX = currentDeck;
		currentDeck->prev->next = currentDeck->next;
		currentDeck->next->prev = currentDeck->prev;
		delete AUX;
	}
	cout << "DECK DELETED SUCCESSFULLY\n";
}
void DEL_CARD(DECKS& decks, int deckIndex, int cardIndex)
{
	int index = 1;
	if (decks.deckNumber < deckIndex || deckIndex < 1)
	{
		cout << "The provided index is out of bounds for the deck list.\n";
		return;
	}
	DECK* currentDeck = decks.first;
	if (currentDeck->cardNumber == 1)
	{
		DEL_DECK(decks, deckIndex);
	}
	currentDeck->cardNumber--;
	while (index < deckIndex)
	{
		currentDeck = currentDeck->next;
		index++;
	}
	index = 1;
	CARD* currentCard = currentDeck->card;
	while (index < cardIndex)
	{
		currentCard = currentCard->next;
		index++;
	}
	CARD* AUX = currentCard;
	if (currentDeck->card == currentDeck->lastCard)
	{
		currentDeck->card = 0;
		delete currentCard;
	}
	else if (currentCard == currentDeck->card) //checks if card is first in deck
	{
		currentDeck->card = currentCard->next;
		currentCard = currentCard->next;
		delete AUX;
		currentCard->prev = 0;
		currentDeck->card = currentCard;
	}
	else if (currentCard == currentDeck->lastCard)
	{
		currentCard = currentCard->prev;
		currentCard->next = 0;
		delete AUX;
		currentDeck->lastCard = currentCard;
	}
	else
	{
		currentCard->prev->next = currentCard->next;
		currentCard->next->prev = currentCard->prev;
		delete AUX;
	}
	cout << "CARD DELETED SUCCESSFULLY\n";
}

void ADD_CARDS(DECKS& decks, int deckIndex, int cardNo)
{
	int index = 1;
	DECK* currentDeck = decks.first;
	if (decks.deckNumber < deckIndex || deckIndex < 1)
	{
		cout << "The provided index is out of bounds for the deck list.\n";
		return;
	}
	while (index < deckIndex)
	{
		currentDeck = currentDeck->next;
		index++;
	}
	currentDeck->cardNumber += cardNo;
	while (index <= cardNo) 
	{
		cout << "\tCard no. " << index << "\n";
		CARD* nou = new CARD;
		int numarCarte;
		char simbolCarte[7];
		cout << "Please enter card number: ";
		cin >> numarCarte;
		while (numarCarte > 14 || numarCarte < 1)
		{
			cout << "ERROR:INVALID CARD NUMBER\n\tPLEASE RE-ENTER CARD NUMBER: ";
			cin >> numarCarte;
		}
		cout << "Please enter card symbol: ";
		cin >> simbolCarte;
		while (strcmp("TREFLA", simbolCarte) && strcmp("CARO", simbolCarte) && strcmp("PICA", simbolCarte) && strcmp("CUPA", simbolCarte))
		{
			cout << "ERROR:INVALID CARD SYMBOL.MAKE SURE CARD SYMBOL IS ONE OF THE FOLLOWING (PICA, CUPA, CARO, TREFLA)\n\tPLEASE RE-ENTER CARD SYMBOL: ";
			cin >> simbolCarte;
		}
		nou->number = numarCarte;
		strcpy_s(nou->symbol, simbolCarte);
		if (currentDeck->card == NULL)
		{
			currentDeck->card = nou;
			currentDeck->lastCard = nou;
			currentDeck->prev = 0;
			currentDeck->next = 0;
		}
		else
		{
			CARD* AUX = currentDeck -> lastCard;
			currentDeck->lastCard->next = nou;
			currentDeck->lastCard = currentDeck->lastCard->next;
			currentDeck->lastCard->prev = AUX;
			currentDeck->lastCard->next = 0;
		}
		index++;
	}
	cout << "CARDS ADDED SUCCESSFULLY\n";
}
void DECK_NUMBER(DECKS& decks)
{
	cout << "The number of decks is " << decks.deckNumber << "\n";
}
void DECK_LEN(DECKS& decks, int deckIndex)
{
	DECK* currentDeck = decks.first;
	int index = 1;
	while (index < deckIndex)
	{
		if (currentDeck == NULL)
		{
			cout << "CARD IS OUT OF BOUNDS";
			return;
		}
		currentDeck = currentDeck->next;
		index++;
	}
	cout << "The length of deck " << index << " is " << currentDeck->cardNumber << "\n";
}
void SHOW_ALL(DECKS& decks)
{
	int index = 1;
	DECK* currentDeck = decks.first;
	if (decks.deckNumber == 0)
	{
		cout << "There are no decks!";
	}
	while (currentDeck != NULL)
	{
		cout << "Deck number " << index << "\n";
		CARD* currentCard = currentDeck->card;
		while (currentCard != NULL)
		{
			cout << "\t" << currentCard->number << " " << currentCard->symbol << "\n";
			currentCard = currentCard->next;
		}
		++index;
		currentDeck = currentDeck->next;
	}
}
void SHOW_DECK(DECKS& decks, int deckNo)
{
	int index = 1;
	DECK* currentDeck = decks.first;
	while (currentDeck != NULL)
	{
		if (index == deckNo)
		{
			cout << "Deck number " << index << "\n";
			CARD* currentCard = currentDeck->card;
			while (currentCard != NULL)
			{
				cout << "\t" << currentCard->number << " " << currentCard->symbol << "\n";
				currentCard = currentCard->next;
			}
		}
		++index;
		currentDeck = currentDeck->next;
	}
}

void SHUFFLE_DECK(DECKS& decks, int deckNo)
{
	DECK* currentDeck = decks.first;
	int index = 1;
	// i should have made a function too late now :))
	if (decks.deckNumber < deckNo || deckNo < 1)
	{
		cout << "The provided index is out of bounds for the deck list.\n";
		return;
	}
	while (index < deckNo)
	{
		currentDeck = currentDeck->next;
		index++;
	}
	CARD* midCard = currentDeck->card;
	index = 1;
	while (index < (currentDeck->cardNumber/2))
	{
		midCard = midCard->next;
		index++;
	}
	currentDeck->lastCard->next = currentDeck->card;
	currentDeck->card->prev = currentDeck->lastCard;
	currentDeck->card = midCard->next;
	currentDeck->lastCard = midCard;
	midCard->next->prev = 0;
	midCard->next = 0;
}
void MERGE_DECKS(DECKS& decks, int deckNo1, int deckNo2)
{
	int index1 = 1, index2 = 1;
	DECK* Deck1 = decks.first;
	DECK* Deck2 = decks.first;
	int index = 1;
	// i should have made a function too late now :))
	if (decks.deckNumber < deckNo1 || decks.deckNumber < deckNo2 || deckNo1 < 1)
	{
		cout << "The provided index is out of bounds for the deck list.\n";
		return;
	}
	while (index < deckNo1)
	{
		Deck1 = Deck1->next;
		index++;
	}
	index = 1;
	while (index < deckNo2)
	{
		Deck2 = Deck2->next;
		index++;
	}
	Deck1->lastCard->next = Deck2->card;
	Deck2->card->prev = Deck1->lastCard;
	Deck2->card = 0;
	Deck2->lastCard = 0;
	Deck1->cardNumber = Deck1->cardNumber + Deck2->cardNumber;
	DEL_DECK(decks, deckNo2);
	cout << "DECKS MERGED SUCCESSFULLY\n";
}
void SPLIT_DECK(DECKS& decks, int deckIndex, int splitIndex)
{
	//i really should have made this into a function :)))))))))))))))))))
	DECK* currentDeck = decks.first;
	if (splitIndex == 0)
	{
		return;
	}
	int index = 1;
	if (decks.deckNumber < deckIndex || deckIndex < 1)
	{
		cout << "The provided index is out of bounds for the deck list.\n";
		return;
	}
	while (index < deckIndex)
	{
		currentDeck = currentDeck->next;
		index++;
	}
	if (currentDeck->cardNumber == splitIndex)
	{
		return;
	}
	DECK* nou = new DECK;
	if (currentDeck->next == NULL)
	{
		nou->next = 0;
		nou->prev = currentDeck;
		currentDeck->next = nou;
		decks.last = nou;
	}
	else
	{
		currentDeck->next->prev = nou;
		nou->next = currentDeck->next;
		nou->prev = currentDeck;
		currentDeck->next = nou;
	}
	index = 1;
	CARD* splitCard = currentDeck->card;
	while (index < splitIndex)
	{
		splitCard = splitCard->next;
		index++;
	}
	decks.deckNumber++;
	nou->card = splitCard->next; //adding cards after split index to the new deck
	nou->lastCard = currentDeck->lastCard;
	currentDeck->lastCard = splitCard;
	splitCard->next->prev = 0;
	splitCard->next = 0;
	currentDeck->next->cardNumber = currentDeck->cardNumber - splitIndex;
	currentDeck->cardNumber = splitIndex;
}
void REVERSE_DECK(DECKS& decks, int deckNo)
{
	DECK* currentDeck = decks.first;
	int index = 1;
	// i should have made a function too late now :))
	if (decks.deckNumber < deckNo || deckNo < 1)
	{
		cout << "The provided index is out of bounds for the deck list.\n";
		return;
	}
	while (index < deckNo)
	{
		currentDeck = currentDeck->next;
		index++;
	}
	CARD* currentCard = currentDeck->lastCard;
	CARD* preCurrentCard = currentCard->prev;
	while (currentCard != currentDeck->card)
	{
		preCurrentCard->next = preCurrentCard->prev;
		preCurrentCard->prev = currentCard;
		currentCard->next = preCurrentCard;
		currentCard = currentCard->next;
		preCurrentCard = preCurrentCard->next;
	}
	currentDeck->card->next = NULL;
	currentDeck->lastCard->prev = NULL;
	currentCard = currentDeck->card;
	currentDeck->card = currentDeck->lastCard;
	currentDeck->lastCard = currentCard;
	
}
void FREE_MEM(DECKS& decks)
{
	int index = decks.deckNumber;
	if (decks.deckNumber == 0)
	{
		cout << "MEMORY FREED SUCCESSFULLY!\n";
		return;
	}
	while (index > 0)
	{
		DEL_DECK(decks, index);
		cout << "\tFREED DECK " << index << " FROM MEMORY\n";
		index--;
	}
	cout << "MEMORY FREED SUCCESSFULLY!\n";
}
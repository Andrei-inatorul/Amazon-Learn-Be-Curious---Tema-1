#pragma once

/*
   _____ _                   _
  / ____| |                 | |
 | (___ | |_ _ __ _   _  ___| |_
  \___ \| __| '__| | | |/ __| __|
  ____) | |_| |  | |_| | (__| |_
 |_____/ \__|_|   \__,_|\___|\__|
*/
struct CARD{
	CARD* next;
	CARD* prev;
	int number;
	char symbol[7];
};

struct DECK {
	CARD* card;
	CARD* lastCard;
	int cardNumber;
	DECK* next;
	DECK* prev;
};

struct DECKS{
	DECK* first;
	int deckNumber;
	DECK* last;
};

/*
  ______                _   _ _
 |  ____|              | | (_|_)
 | |__ _   _ _ __   ___| |_ _ _
 |  __| | | | '_ \ / __| __| | |
 | |  | |_| | | | | (__| |_| | |
 |_|   \__,_|_| |_|\___|\__|_|_|
*/
void DRAW_INTERFACE( void );
void ADD_DECK(DECKS& Decks, int cardNo);
void DEL_DECK(DECKS& decks, int deckNo);
void DEL_CARD(DECKS& decks, int deckIndex, int cardIndex);
void ADD_CARDS(DECKS& decks, int deckIndex, int cardNo);
void DECK_NUMBER(DECKS& decks);
void DECK_LEN(DECKS& decks, int deckIndex);
void SHOW_ALL(DECKS& decks);
void SHOW_DECK(DECKS& decks, int deckNo);
void SHUFFLE_DECK(DECKS& decks, int deckNo);
void MERGE_DECKS(DECKS& decks, int deck1, int deck2);
void SPLIT_DECK(DECKS& decks, int deckIndex, int splitIndex);
void REVERSE_DECK(DECKS& decks, int deckNo);
void FREE_MEM(DECKS& decks); //frees memory when exitting

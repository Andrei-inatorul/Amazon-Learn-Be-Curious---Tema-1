**Nume:** Lefter Andrei
**Grupă:** 1108A

## Learn & Be Curious - Tema 1

##### Scurtă descriere a funcționalității temei
##### Descriere:
* Descriere structuri:
```c++
   _____ _                   _
  / ____| |                 | |
 | (___ | |_ _ __ _   _  ___| |_
  \___ \| __| '__| | | |/ __| __|
  ____) | |_| |  | |_| | (__| |_
 |_____/ \__|_|   \__,_|\___|\__|
struct CARD{
	CARD* next;
	CARD* prev;
	int number;
	char symbol[7];
};

struct DECK {       //reprezinta un pachet, fiecare pachet are un pointer la  
	CARD* card;         // pachetul anterior si unul la pachetul urmator , 
	CARD* lastCard;         // precum si un pointer la prima carte din pachet
	int cardNumber;         // cat si unul la ultima carte pentru ca adaugarea la final
	DECK* next;             // de pachet a unor carti noi sa fie mai rapida + 
	DECK* prev;             // + numarul de carti care este actualizat de fiecare data
};                          // cand se ruleaza o functie care il poate modifica

struct DECKS{   //salveaza primul si ultimul pachet + numarul de pachete
	DECK* first; 
	int deckNumber;
	DECK* last;
};
```
>Adaugarea de carti cat si afisarea numarului de pachete/carti au eficienta de timp sporita datorita implementarii alese.
* Eventuale explicații suplimentare pentru anumite părți din temă ce crezi că nu sunt suficient de clare doar urmărind codul
> --
### Comentarii asupra temei:
>Nu am apucat sa realizez functia pentru sortarea  asa ca aceasta nu va fi inclusa in tema, dar voi posta o varianta care sa contina si aceasta functie in zilele urmatoare pe contul meu de github : https://github.com/Andrei-inatorul
* Crezi că ai fi putut realiza o implementare mai bună?
>Pe ici pe colo sunt sigur ca as putea face modificari care sa mareasca eficienta programului. In plus, am utilizat unele segmente de cod de mai multe ori in loc sa fac o functie, fapt pe care nu il consider "good practice". 
* Ce ai invățat din realizarea acestei teme?
>Din realizarea acestei temei consider ca mi-am imbunatatit lucrul cu liste 
* Alte comentarii
> Known Issues:
>*Atunci cand in loc de valoarea numarului de care (intreg) se introduce un caracter programul intra intr-o bucla infinita si afiseaza o eroare
>>**INDEXAREA PACHETELOR CAT SI A CARTILOR SE FACE DE LA 1!!!**
>Avand in vedere abordarea cu alocare dinamica nu are importanta de unde se incepe indexarea,am inceput cu 1 deoarece mi se parea mai logic.
### (Opțional) Resurse / Bibliografie:
>Ascii art-ul utilizat este preluat de pe site-ul: https://ascii.co.uk/art/spades
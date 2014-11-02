#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

/* Pour centrer */
#define CENTER_X 0 
#define CENTER_Y 0
#define T_CASE 1

/* Structure de position */
typedef struct _Position
{
	int x, y;
}Position;

typedef enum _boolean { FALSE, TRUE } bool;

/* Structure de gestion d'entrées clavier/souris */
typedef struct _input
{
	SDL_Event event;
	int clicX, clicY;
	int cursorX, cursorY;
	bool mouseButton[8];
	bool keyboardButton[SDL_NUM_SCANCODES];
	bool end;
}Input;


/* Initialise la structure de gestion d'entrées clavier et souris */
Input initInput();
	
/* Met à jour les événements clavier et souris entrés par l utilisateur */
void updateEvents(Input *input);

/* Renvoie la position d'un clic de souris */
Position clicPosition(int clicX, int clicY);

#endif

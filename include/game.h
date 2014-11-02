#ifndef _GAME_H
#define _GAME_H

#include <stdlib.h>
#include <time.h>
#include "affichage.h"

typedef enum _difficulty
{
	VERY_EASY, EASY, MEDIUM, HARD, EXTREME
}Difficulty;

Difficulty chooseDifficulty(Affichage A);
int setNbMystere(Difficulty difficulty);
void initGame(Affichage A, int *nbMystere);
int askNumber(Affichage A);
void playGame(Affichage A, int nbMystere);

#endif

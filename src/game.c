#include "game.h"
#include "timer.h"
#include "error.h"
#include "textBox.h"

/* INITIALISATION */

Difficulty chooseDifficulty(Affichage A)
{
	Input input = initInput();
	Timer t = initTimer();
	
	drawTile(A, TILE_DIFFICULTY);
	
	while(1)
	{
		setTimer(&t);
		updateEvents(&input);
		
		if (clicValide( clicPosition(input.clicX, input.clicY) , A.buttons[BUTTON_VEASY] ) ) 
		{
			return VERY_EASY;
		}
		if (clicValide( clicPosition(input.clicX, input.clicY) , A.buttons[BUTTON_EASY] ) ) 
		{
			return EASY;
		}
		if (clicValide( clicPosition(input.clicX, input.clicY) , A.buttons[BUTTON_MEDIUM] ) ) 
		{
			return MEDIUM;
		}
		if (clicValide( clicPosition(input.clicX, input.clicY) , A.buttons[BUTTON_HARD] ) ) 
		{
			return HARD;
		}
		if (clicValide( clicPosition(input.clicX, input.clicY) , A.buttons[BUTTON_XTREM] ) ) 
		{
			return EXTREME;
		}
		if(input.end)
		{
			exit(EXIT_SUCCESS);
		}
		
		reguleFPS(&t);
	}
	
	return ERR_DIFFICULTY;
}

int setNbMystere(Difficulty difficulty)
{
	int nbMystere, max = 10;
	srand(time(NULL));
	
	if (difficulty < VERY_EASY && difficulty > EXTREME )
	{
		return ERR_DIFFICULTY;
	}
	
	switch(difficulty)
	{
		case VERY_EASY: max = 100;break;
		case EASY: max = 1000;break;
		case MEDIUM: max = 10000;break;
		case HARD: max = 100000;break;
		case EXTREME: max = 1000000;break;
	}
	
	nbMystere = rand() % max;
	return nbMystere;
}

void initGame(Affichage A, int *nbMystere)
{
	Difficulty diff;
	diff = chooseDifficulty(A);
	*nbMystere = setNbMystere(diff);
}

/* JEU */


void drawCounter(Affichage A, int i)
{
	Font font = initFont();
	SDL_Color color = newColor(0,0,0);
	Button pos = newPosition(140, 449, 30, 24);
	char* counter = malloc(4);
	loadFonts(&font);
	snprintf(counter, 3,"%d" , i);
	SDL_RenderFillRect(A.screen, &pos);
	drawText(font, 0, A, counter, color, pos);
	free(counter);
}

int askNumber(Affichage A)
{
	TextBox txtBox = initTextBox();
	int n;
	
	while(1)
	{
		updateInputEvents(A, &txtBox);
		
		if ( (n = convertStringToInteger(txtBox.text)) != ERR_NUMBER)
			return n;
	}
}

void playGame(Affichage A, int nbMystere)
{
	int i, n = 0;
	Timer t = initTimer();
	
	drawTile(A, TILE_GAME);
	
	for(i = 0; n != nbMystere ; i++)
	{
		setTimer(&t);
		
		n = askNumber(A);
		
		if(n < nbMystere)
		{
			drawTile(A, TILE_MORE);
			SDL_Delay(1000);
			drawTile(A, TILE_GAME);
			/* C est plus, redemander un nombre */     
        }
        
        else if(n > nbMystere)
        {
			drawTile(A, TILE_LESS);
			SDL_Delay(1000);
			drawTile(A, TILE_GAME);
			/* C est moins, redemander un nombre */
		}
		
		drawCounter(A, i+1);
		reguleFPS(&t);
	}	
	
	drawTile(A, TILE_WIN);
	SDL_Delay(3000);
}


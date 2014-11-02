#include "affichage.h"

Affichage initAffichage()
{
	Affichage affichage;
	int i;

	affichage.window = NULL;
	affichage.screen = NULL;
	
	for(i = 0; i < MAX_TILES ; i++)
		affichage.interface[i] = NULL;
	
	initSDL(&affichage);
	
	SDL_SetWindowTitle(affichage.window, TITLE);

	loadTextures(&affichage);
	
	setButtonsPositions(&affichage);
	
	setPositionsCibles(&affichage);
	
	SDL_SetRenderDrawColor(affichage.screen,COLOR_R,COLOR_G,COLOR_B,COLOR_A);
	SDL_RenderClear(affichage.screen);

	return affichage;
}

void deleteAffichage(Affichage *A)
{
	int i;
	for (i = 0; i < MAX_TILES ; i++)
		SDL_DestroyTexture(A->interface[i]);
		
	SDL_DestroyRenderer(A->screen);
	SDL_DestroyWindow(A->window);
	IMG_Quit();
	SDL_Quit();
}

void initSDL(Affichage *affichage)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0 )
	{
		fprintf(stderr, "Impossible d initialiser le mode vidéo: %s", SDL_GetError() );
		exit(EXIT_FAILURE);
	}
	
	if (SDL_CreateWindowAndRenderer(W_SCREEN, H_SCREEN, 
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL, &((*affichage).window), &((*affichage).screen)) != 0)
	{
		fprintf(stderr, "Impossible d initialiser la fenêtre: %s", SDL_GetError() );
		exit(EXIT_FAILURE);
	}
	
	if ( IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0 )
	{
		fprintf(stderr,"Impossible d'initialiser l'image : %s \n", IMG_GetError() );
		exit(EXIT_FAILURE);
	}
}

void loadTextures(Affichage *A)
{
	A->interface[TILE_FILL] = IMG_LoadTexture(A->screen, "img/fillscreen.png");
	if (A->interface[TILE_FILL] == NULL)
	{
		fprintf(stderr,"Erreur :: %s", IMG_GetError() );
		exit(EXIT_FAILURE);
	}
	
	A->interface[TILE_MENU] = IMG_LoadTexture(A->screen, "img/menu.png");
	if (A->interface[TILE_MENU] == NULL)
	{
		fprintf(stderr,"Erreur :: %s", IMG_GetError() );
		exit(EXIT_FAILURE);
	}
	
	A->interface[TILE_DIFFICULTY] = IMG_LoadTexture(A->screen, "img/difficulty.png");
	if (A->interface[TILE_DIFFICULTY] == NULL)
	{
		fprintf(stderr,"Erreur :: %s", IMG_GetError() );
		exit(EXIT_FAILURE);
	}
	
	A->interface[TILE_GAME] = IMG_LoadTexture(A->screen, "img/game.png");
	if (A->interface[TILE_GAME] == NULL)
	{
		fprintf(stderr,"Erreur :: %s", IMG_GetError() );
		exit(EXIT_FAILURE);
	}
	
	A->interface[TILE_MORE] = IMG_LoadTexture(A->screen, "img/more.png");
	if (A->interface[TILE_MORE] == NULL)
	{
		fprintf(stderr,"Erreur :: %s", IMG_GetError() );
		exit(EXIT_FAILURE);
	}
	
	A->interface[TILE_LESS] = IMG_LoadTexture(A->screen, "img/less.png");
	if (A->interface[TILE_LESS] == NULL)
	{
		fprintf(stderr,"Erreur :: %s", IMG_GetError() );
		exit(EXIT_FAILURE);
	}
	
	A->interface[TILE_WIN] = IMG_LoadTexture(A->screen, "img/win.png");
	if (A->interface[TILE_WIN] == NULL)
	{
		fprintf(stderr,"Erreur :: %s", IMG_GetError() );
		exit(EXIT_FAILURE);
	}
	
}

void drawTile (Affichage A, Tiles noTile)
{
	SDL_RenderCopy(A.screen, A.interface[noTile], NULL, &A.positions[noTile]);
	SDL_RenderPresent(A.screen);
}

Button newButton(int x, int y, int w, int h)
{
	Button r;
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	return r;
}

bool clicValide(Position clic, Button button)
{
	if (button.x <= clic.x && clic.x <= button.x + button.w
		&& button.y <= clic.y && clic.y <= button.y + button.h)
		return TRUE;
	return FALSE;
}

void setButtonsPositions(Affichage *A)
{
	A->buttons[BUTTON_PLAY] = newButton(X_PLAY, Y_PLAY, W_PLAY, H_PLAY);
	A->buttons[BUTTON_QUIT] = newButton(X_QUIT, Y_QUIT, W_PLAY, H_PLAY);
	A->buttons[BUTTON_VEASY] = newButton(X_VEASY, Y_VEASY, W_DIFF, H_DIFF);
	A->buttons[BUTTON_EASY] = newButton(X_EASY, Y_EASY, W_DIFF, H_DIFF);
	A->buttons[BUTTON_MEDIUM] = newButton(X_MEDIUM, Y_MEDIUM, W_DIFF, H_DIFF);
	A->buttons[BUTTON_HARD] = newButton(X_HARD, Y_HARD, W_DIFF, H_DIFF);
	A->buttons[BUTTON_XTREM] = newButton(X_XTREM, Y_XTREM, W_DIFF, H_DIFF);
	
}

void setPositionsCibles(Affichage *A)
{
	int i;
	for (i = 0; i < MAX_TILES ; i++)
	{
		A->positions[i] = newButton(0,0,W_SCREEN,H_SCREEN);
	}
	
	A->positions[TILE_MORE] = newButton(MORE_X, MORE_Y, MORE_W, MORE_H);
	A->positions[TILE_LESS] = A->positions[TILE_MORE];
	A->positions[TILE_WIN] = newButton(WIN_X, WIN_Y, WIN_W, WIN_H);
}

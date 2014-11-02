#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "input.h"

/* Titre du programme */
#define TITLE "Jeu du nombre mystère"

/* Dimensions de la fenetre */
#define W_SCREEN 640
#define H_SCREEN 480

/** Positions cibles */

/* Nombre de fois ou on affiche l image */
#define N 1

/* Largeur et hauteur des sprites */
#define WIN_W 362
#define WIN_H 165
#define WIN_X (W_SCREEN - (N * WIN_W))/2
#define WIN_Y (H_SCREEN - (N * WIN_H))/2

#define MORE_W 100
#define MORE_H 200
#define MORE_X 500
#define MORE_Y 250

/* Couleur de fond */
#define COLOR_R 255
#define COLOR_G 255
#define COLOR_B 255
#define COLOR_A 255

/* Positions des boutons */

#define W_PLAY 369
#define H_PLAY 73

#define W_DIFF 484
#define H_DIFF 38

#define X_PLAY 147
#define Y_PLAY 185

#define X_QUIT 150
#define Y_QUIT 318

#define X_VEASY 89
#define Y_VEASY 143

#define X_EASY 89
#define Y_EASY 186

#define X_MEDIUM 89
#define Y_MEDIUM 235

#define X_HARD 89
#define Y_HARD 287

#define X_XTREM 89
#define Y_XTREM 344

#define BUTTON_PLAY 0
#define BUTTON_QUIT 1
#define BUTTON_VEASY 2
#define BUTTON_EASY 3
#define BUTTON_MEDIUM 4
#define BUTTON_HARD 5
#define BUTTON_XTREM 6


#define MAX_BUTTONS 7

/* ... etc. */


#define MAX_TILES 7

typedef enum _Tiles
{
	TILE_FILL,
	TILE_MENU,
	TILE_DIFFICULTY,
	TILE_GAME,
	TILE_MORE,
	TILE_LESS,
	TILE_WIN	
}Tiles;

typedef SDL_Rect Button;

typedef struct _Drawer
{
	SDL_Window* window; /* Fenetre */
	SDL_Renderer* screen; /* Renderer */
	SDL_Texture* interface[MAX_TILES]; /* Sprites */
	Button positions[MAX_TILES]; /* Positions cibles */
	Button buttons[MAX_BUTTONS]; /* Boutons du jeu */
}Affichage;

Affichage initAffichage();
void deleteAffichage(Affichage *A);
void initSDL(Affichage*);
void loadTextures(Affichage *A);
void drawTile (Affichage A, Tiles noTile);
Button newButton(int x, int y, int w, int h);
bool clicValide(Position clic, Button button);
void setButtonsPositions(Affichage *A);
void setPositionsCibles(Affichage *A);

#endif

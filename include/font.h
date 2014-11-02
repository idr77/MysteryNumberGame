#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "affichage.h"

/* Nombre de polices */
#define MAX_FONT 1

/* Nom du fichier de la police */
#define FILE_FONT "font/SIXTY.TTF"

/* Exemple */
#define EX_FONT 0
#define SIZE_EX_FONT 50

typedef struct _Font
{
	TTF_Font* font[MAX_FONT];
}Font;

Font initFont();
void loadFonts(Font*);
void deleteFont(Font *font);
SDL_Color newColor(int r, int g, int b);
SDL_Rect newPosition(int x, int y, int w, int h);
void drawText(Font font, int noFont, Affichage A, char *txt, SDL_Color color, SDL_Rect pos);

#include "font.h"

Font initFont()
{
	Font font;
	int i;
	
	for (i = 0; i < MAX_FONT ; i++)
		font.font[i] = NULL;

	if(!TTF_WasInit() && TTF_Init() == -1)
	{
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
	
	loadFonts(&font);
	return font;
}

void loadFonts(Font *font)
{
	font->font[EX_FONT] = TTF_OpenFont(FILE_FONT, SIZE_EX_FONT );
}

void deleteFont(Font *font)
{
	int i;
	for (i = 0; i < MAX_FONT ; i++)
		TTF_CloseFont(font->font[i]);
	
	TTF_Quit();
}

SDL_Color newColor(int r, int g, int b)
{
	SDL_Color color;
	color.r = r;
	color.g = g;
	color.b = b;
	return color;
}

SDL_Rect newPosition(int x, int y, int w, int h)
{
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	return r;
}

void drawText(Font font, int noFont, Affichage A, char *txt, SDL_Color color, SDL_Rect pos)
{
	SDL_Surface *surfaceTexte = NULL;
	SDL_Texture *textureTexte = NULL;
	
	surfaceTexte = TTF_RenderText_Solid(font.font[noFont], txt, color);
	
	textureTexte = SDL_CreateTextureFromSurface(A.screen, surfaceTexte);
	SDL_FreeSurface(surfaceTexte);
	
	SDL_RenderCopy(A.screen, textureTexte, NULL, &pos);
	SDL_RenderPresent(A.screen);
	SDL_DestroyTexture(textureTexte);
}

	

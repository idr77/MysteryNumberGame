#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "font.h"

typedef struct _InputEvent
{
	SDL_Event event;
	bool keyboardButton[SDL_NUM_SCANCODES];
	bool end;
	int cursor;
	int length;
}InputEvent;

typedef struct _TextBox
{
	Font font;
	SDL_Rect position;
	InputEvent input;
	char *text;                                                             
}TextBox;




#define W_TEXTBOX 228
#define H_TEXTBOX 94
#define X_TEXTBOX 226
#define Y_TEXTBOX 211


SDL_Rect newRect(int x, int y, int w, int h);
InputEvent initInputEvent();
TextBox initTextBox();
void updateInputEvents(Affichage A, TextBox *textBox);
bool isNumber(const char *s);
int convertStringToInteger(const char *s);

#endif

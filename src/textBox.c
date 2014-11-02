#include "textBox.h"
#include "error.h"

SDL_Rect newRect(int x, int y, int w, int h)
{
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	return r;
}

InputEvent initInputEvent()
{
	InputEvent e;
	int i;
	
	for (i = 0; i < SDL_NUM_SCANCODES ; i++)
		e.keyboardButton[i] = FALSE;
	e.end = FALSE;
	return e;
}

TextBox initTextBox()
{
	TextBox tbox;
	
	tbox.position = newRect(X_TEXTBOX, Y_TEXTBOX, W_TEXTBOX, H_TEXTBOX);
	
	tbox.font = initFont();
	loadFonts(&tbox.font);
	
	tbox.input = initInputEvent();
	
	tbox.text = NULL;
	tbox.text = (char*) calloc(50,sizeof(char));
	if(!tbox.text)
		exit(EXIT_FAILURE);
	
	return tbox;
}

void clearTextBox(TextBox textBox, Affichage A)
{
	SDL_RenderFillRect(A.screen, &textBox.position);
}

void updateInputEvents(Affichage A, TextBox *textBox)
{
	bool done = FALSE;
	SDL_SetTextInputRect(&textBox->position);
	SDL_StartTextInput();
	
	while(!done)
	{
		if(SDL_PollEvent(&textBox->input.event))
		{
			switch(textBox->input.event.type)
			{
				case SDL_WINDOWEVENT:
					if (textBox->input.event.window.event == SDL_WINDOWEVENT_CLOSE)
					{
						textBox->input.end = TRUE;
						exit(EXIT_SUCCESS);
					}
				break;
				
				case SDL_TEXTINPUT:
					/* Ajoute le texte à la fin de notre texte */
					strcat(textBox->text, textBox->input.event.text.text);
				break;
				
				case SDL_TEXTEDITING:
					/*
					 * Met à jour la composition du texte
					 * MET À JOUR LA POSITION DU CURSEUR
					 * Met à jour la longueur de la sélection (si il y en a)
					*/
				   textBox->text = textBox->input.event.edit.text;
				   textBox->input.cursor = textBox->input.event.edit.start;
				   textBox->input.length = textBox->input.event.edit.length;
				break;
				
				case SDL_KEYDOWN:
					if (textBox->input.event.key.keysym.scancode == SDL_SCANCODE_RETURN)
					{
						done = TRUE;
					}
				break;
				
			}
		}
		clearTextBox(*textBox, A);
		drawText(textBox->font, 0, A, textBox->text, newColor(0,0,0), textBox->position);
	}	
	
	SDL_StopTextInput();
}

bool isNumber(const char *s)
{
	int i;
	for (i = 0; i != '\0' ; i++)
	{
		if(!isdigit(s[i]))
			return FALSE;
	}
	return TRUE;
}

int convertStringToInteger(const char *s)
{
	if (isNumber(s))
		return atoi(s);
	return ERR_NUMBER;
}

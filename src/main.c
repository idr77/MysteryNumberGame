#include <stdio.h>
#include <stdlib.h>

#include "game.h"

int main(int argc, char *argv[])
{
	Affichage A = initAffichage();
	int nbMystere = 0;
	
	initGame(A, &nbMystere);
	playGame(A, nbMystere);
	
	deleteAffichage(&A);
	return EXIT_SUCCESS;
}

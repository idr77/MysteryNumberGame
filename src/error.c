#include "error.h"
#include <stdio.h>
#include <stdlib.h>

void setError(Errors *errors[], Error errCode, char* error)
{
	errors[-errCode]->errCode = errCode;
	errors[-errCode]->descError = error;
}

char* getError(Errors errors[], Error errCode)
{
	return errors[-errCode].descError;
}

void manageErrors(Errors *errors[], Error errCode)
{
	if (errCode == ERR_NUMBER)
	{
		setError(errors, ERR_NUMBER, "Erreur :: nombre incorrect");
		fprintf(stderr, "%s\n", getError(errors, ERR_NUMBER) );
	}
	
	else if (errCode == ERR_DIFFICULTY)
	{
		setError(errors, ERR_DIFFICULTY, "Erreur :: Difficulté inexistante");
		fprintf(stderr, "%s\n", getError(errors, ERR_DIFFICULTY));
	}
	
	exit(errCode);
}

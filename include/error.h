#ifndef _ERROR_H
#define _ERROR_H

#define DEBUG
#define MAX_ERRORS 2
typedef enum _Error
{
	ERR_DIFFICULTY = -1, ERR_NUMBER = -2
}Error;

typedef struct _Errors
{
	Error errCode;
	char* descError;
}Errors;


#endif

#include "monty.h"
#include "global.h"

char **token;


/**
 * initGlobal - initialize global variable
 * @count: variable for the number of rows in token
 * Return: None
 */

void initGlobal(int count)
{
	token = malloc(sizeof(char *) * (count + 2));
}

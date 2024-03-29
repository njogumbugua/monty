#include "monty.h"
#include "global.h"

/**
 * malloc_error - cannot allocate memory
 * Return: None
 */

void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * free_2d - free 2d array
 * @token: 2d token
 * Return: None
 */

void free_2d(char **token)
{
	int i;

	i = 0;
	while (token[i] != NULL)
	{
		free(token[i]);
		i++;
	}
	free(token);
}

/**
 * exit_free - exit program and free memory
 * @token: 2d array
 * @fd: file descriptor
 * Return: None
 */

void exit_free(char **token, FILE *fd)
{
	free_2d(token);
	fclose(fd);
	exit(EXIT_FAILURE);
}

/**
 * free_stack - free stack of linked list
 * @stack: head of the stack
 * Return: None
 */

void free_stack(stack_t **stack)
{
	stack_t *temp;

	while ((*stack) != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

#include "main.h"

/**
 * tokenization - tokenize line into 2d array
 * @line: command line to be tokenized
 * @fd: file descriptor
 * Return: 2d array tokenized command
 */

char **tokenization(char *line, FILE *fd)
{
	char **token;
	char *word;
	int count;
	int i;

	count = 0;
	word = strtok(line, " ");
	if (strcmp(word, "push") == 0)
		count = 1;

	token = malloc(sizeof(char *) * (count + 2));
	if (token == NULL)
	{
		free(line);
		fclose(fd);
		malloc_error();
	}

	i = 0;
	while (word != NULL && i <= count)
	{

		token[i] = malloc(sizeof(char) * (strlen(word) + 1));
		if (token[i] == NULL)
		{
			free(line);
			free(word);
			free_2d(token);
			fclose(fd);
			malloc_error();
		}

		strcpy(token[i], word);
		token[i][strcspn(token[i], "\n")] = 0;

		word = strtok(NULL, " ");
		i++;
	}
	token[i] = NULL;
	return (token);
}

/**
 * search_command - search for command in opcode array
 * @command: command name
 * @op: array to be searched
 * @len: len of op array
 * Return: 1 on Success
 */

int search_command(char *command, instruction_t *op, const int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		if (strcmp(command, op[i].opcode) == 0)
			return (1);
		i++;
	}

	return (-1);
}

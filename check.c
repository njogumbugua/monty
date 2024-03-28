#include "monty.h"
#include "global.h"

/**
 * check_zero - check if string is zero
 * @str: string to be checked
 * Return: 1 on Success
 */

int check_zero(char *str)
{
	if (str[0] == '-')
	{
		if (str[1] == '0')
		{
			if (str[2] == '\0')
				return (1);
		}
	}
	if (str[0] == '0' && str[1] == '\0')
		return (1);
	return (0);
}

/**
 * check_num_args - check number of arguments
 * @argc: number of arguments
 * Return: None
 */


void check_num_args(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * get_name - get the name of program from path to use in error message
 * @path: full path to program
 * Return: name of program
 */

char *get_name(char *path)
{
	int i, start, end, len;
	char *name;

	i = 0, start = 0, end = 0;

	while (path[i] != '\0')
	{
		if (path[i] == '/')
			start = i + 1;
		end++;
		i++;
	}
	len = end - start + 1;
	name = malloc(sizeof(char) * len);
	if (name == NULL)
		malloc_error();
	strncpy(name, path + start, len);

	return (name);
}

/**
 * check_file_status - check file status after open
 * @fd: file descriptor
 * @file_path: file path to extract file name
 * Return: None
 */

void check_file_status(FILE *fd, char *file_path)
{
	char *file_name;

	file_name = get_name(file_path);
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		free(file_name);
		exit(EXIT_FAILURE);
	}
	free(file_name);
}

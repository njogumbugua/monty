#include "main.h"
#include <stdlib.h>

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments passed from CL
 * Return: always 0 (Success)
 */

int main(int argc, char *argv[])
{
	FILE *fd;
	unsigned int line_number;
	char *line;
	size_t len;
	ssize_t nread;
  len = 0;
  line = NULL;
  char **tokens;

	line_number = 0;
	check_num_args(argc);
	fd = fopen(argv[1], "r");
	check_file_status(fd, argv[1]);
  nread = getline(&line, &len, fd);

	while((nread != -1))
	{
		line_number++;

		/* Tokenization */
    tokens = tokenize_commands(line);

		/* Command valid? */
		/* argument valid? */

		printf("%p", tokens);
    free(tokens);
	}
	return (0);
}

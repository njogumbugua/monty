#include "main.h"

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

	check_num_args(argc);
	fd = fopen(argv[1], "r");
	check_file_status(fd, argv[1]);
	line_number = 0;

	while((nread = getline(&line, &len, fd)) != -1)
	{
		line_number++;

		/* Tokenization */

		/* Command valid? */
		/* argument valid? */

		printf("%s", line);
	}
	return (0);
}

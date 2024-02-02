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
	char **token;
	const int LEN_OP = 7;
	int st;

	instruction_t op[LEN_OP];

	line = NULL;
	len = 0;
	init_op(op);
	check_num_args(argc);
	fd = fopen(argv[1], "r");
	check_file_status(fd, argv[1]);
	line_number = 0;

	while ((nread = getline(&line, &len, fd)) != -1)
	{
		line_number++;
		/* Tokenization */
		token = tokenization(line, fd);
		/* Command valid? */
		st = search_command(token[0], op, LEN_OP);
		if (st == -1)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token[0]);
			exit_free(token, line, fd);
		}
		/* argument valid? */
		free_2d(token);
	}
	free_2d(token);
	free(line);
	return (0);
}

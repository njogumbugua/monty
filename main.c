#include "main.h"
#include "global.h"

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
	const int LEN_OP = 11;
	int st;
	stack_t *stack;
	instruction_t op[11];

	line = NULL;
	len = 0;
	init_op(op);
	check_num_args(argc);
	fd = fopen(argv[1], "r");
	check_file_status(fd, argv[1]);
	line_number = 0;
	stack = NULL;

	while ((nread = getline(&line, &len, fd)) != -1)
	{
		line_number++;
		tokenization(line, fd);
		st = search_command(token[0], op, LEN_OP);
		if (st == -1)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token[0]);
			exit_free(token, line, fd);
		}

		op[st].f(&stack, line_number);
		free_2d(token);
	}
	free(line);
	fclose(fd);
	return (0);
}

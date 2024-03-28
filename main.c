#include "monty.h"
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
	char *nread;
	char str[100];
	const int LEN_OP = 11;
	int st;
	stack_t *stack;
	instruction_t op[11];

	init_op(op);
	check_num_args(argc);
	fd = fopen(argv[1], "r");
	check_file_status(fd, argv[1]);
	line_number = 0;
	stack = NULL;

	while ((nread = fgets(str, 100, fd)) != NULL)
	{
		line_number++;
		tokenization(str, fd);
		st = search_command(token[0], op, LEN_OP);
		if (st == -1)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token[0]);
			free_stack(&stack);
			exit_free(token, fd);
		}
		if (op[st].f(&stack, line_number) == 1)
		{
			free_2d(token);
		} else
		{
			free_stack(&stack);
			exit_free(token, fd);
		}
	}
	free_stack(&stack);
	fclose(fd);
	return (0);
}

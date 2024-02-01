#include "main.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments passed from CL
 * Return: always 0 (Success)
 */

int main(int argc, char *argv[])
{
	check_num_args(argc);

  char *filename = argv[1];
  printFileContent(filename);

	return (0);
}

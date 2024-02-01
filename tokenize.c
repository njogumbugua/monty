#include "main.h"

/**
 * tokenize_commands - tokenize file input
 *
 * @line: input from user
 *
 * Return: tokenized file input
 */

char **tokenize_commands(char *line)
{
  int bufsize = TOKEN_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char *));
  char *token;

  if (!tokens)
  {
    perror("allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, TOKEN_DELIM);
  while (token != NULL)
  {
    tokens[position] = token;
    position++;

    if (position >= bufsize)
    {
      bufsize += TOKEN_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char *));
      if (!tokens)
      {
        perror("allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, TOKEN_DELIM);
  }
  tokens[position] = NULL;
  return (tokens);
}

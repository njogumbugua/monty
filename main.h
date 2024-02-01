#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TOKEN_BUFSIZE 64
#define TOKEN_DELIM "\t "

void check_num_args(int argc);
void check_file_status(FILE *fd, char *file_name);
char *get_name(char *path);
char **tokenize_commands(char *line);
#endif

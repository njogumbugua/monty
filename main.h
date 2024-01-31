#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void check_num_args(int argc);
void check_file_status(FILE *fd, char *file_name);
char *get_name(char *path);
#endif

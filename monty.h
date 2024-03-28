#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/* Data sturctures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        int (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* main functions */

void initGlobal(int count);
void check_num_args(int argc);
void check_file_status(FILE *fd, char *file_name);
char *get_name(char *path);
char **tokenization(char *line, FILE *fd);

int search_command(char *command, instruction_t *op, const int len);

/* Errors */

void malloc_error(void);
void free_2d(char **token);
void exit_free(char **token, FILE *fd);
void free_stack(stack_t **stack);

/* opcode */

void init_op(instruction_t *op);

/* builtins implementation */
int push(stack_t **stack, unsigned int line_number);
int pall(stack_t **stack, unsigned int line_number);
int pint(stack_t **stack, unsigned int line_number);
int pop(stack_t **stack, unsigned int line_number);
int swap(stack_t **stack, unsigned int line_number);
int add(stack_t **stack, unsigned int line_number);
int nop(stack_t **stack, unsigned int line_number);
int sub(stack_t **stack, unsigned int line_number);
int _div(stack_t **stack, unsigned int line_number);
int mul(stack_t **stack, unsigned int line_number);
int mod(stack_t **stack, unsigned int line_number);

#endif

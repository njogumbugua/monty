#include "main.h"
#include <string.h>

void init_op(instruction_t *op)
{
	op[0].opcode = "push";
	op[0].f = push;

	op[1].opcode = "pall";
	op[1].f = pall;

	op[2].opcode = "pint";
	op[2].f= pint;

	op[3].opcode = "pop";
	op[3].f = pop;

	op[4].opcode = "swap";
	op[4].f = swap;

	op[5].opcode = "add";
	op[5].f = add;

	op[6].opcode = "nop";
	op[6].f = nop;

}

/**
  * push - adds an elements to top of stack
  * @stack: stack top
  * @line_number: script line being execution
  */
void push(stack_t **stack, unsigned int line_number)
{
  int value;
  char *value_str; 
  value_str = strtok(NULL, "\n\t");
  stack_t *new_node; 
  new_node = malloc(sizeof(stack_t));
  value = atoi(value_str);
  if (!new_node)
  {
    perror("Error allocating memory");
    exit(EXIT_FAILURE);
  }

  if (!value)
  {
    fprintf(stderr, "L%d: usage: integer\n", line_number);
  }
  new_node->prev = NULL;
  new_node->n = value;
  new_node->next = *stack;

  if (*stack)
  {
    (*stack)->prev = new_node;
  }
  *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}


void pint(stack_t **stack, unsigned int line_number)
{
  if (*stack)
  {
    printf("%d\n", (*stack)->n);
  }
  else
  {
    fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
    exit(EXIT_FAILURE);
  }
}

void pop(stack_t **stack, unsigned int line_number)
{
  if (!*stack)
  {
    fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
    exit(EXIT_FAILURE);
  }

    // Remove the top node from the stack
    stack_t *top = *stack;
    *stack = top->next;

    // Free the memory of the removed node
    free(top);
}

void swap(stack_t **stack, unsigned int line_number)
{
  if (*stack && (*stack)->next)
  {
    int temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
  }
  else
  {
    fprintf(stderr, "L%u: can't swap, stack has less than two elements\n", line_number);
    exit(EXIT_FAILURE);
  }

  printf("swap\n");
}

void add(stack_t **stack, unsigned int line_number)
{
  if (*stack && (*stack)->next)
  {
    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
  }
  else
  {
    fprintf(stderr, "L%u: can't add, stack has less than two elements\n", line_number);
    exit(EXIT_FAILURE);
  }
}

void nop(stack_t **stack, unsigned int line_number)
{
  (void)stack;
  (void)line_number;
   printf("nop\n");
}

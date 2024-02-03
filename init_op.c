#include "main.h"

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

void push(stack_t **stack, unsigned int line_number)
{
    // Extract the value to be pushed from the line and convert it to an integer
    char *value_str = strtok(NULL, " \n\t");
    if (!value_str)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int value = atoi(value_str);

    // Allocate memory for a new stack node
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    // Initialize the new node
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    // Update the previous pointer of the current top node if it exists
    if (*stack)
    {
        (*stack)->prev = new_node;
    }

    // Update the stack pointer to the new node
    *stack = new_node;

  printf("Executing push at line %u\n", line_number);
}

void pall(stack_t **stack, unsigned int line_number)
{
  // Implement pall operation here
  stack_t *current = *stack;
    while (current != NULL)
    {
      printf("%d\n", current->n);
      current = current->next;
    }
  printf("Executing pall at line %u\n", line_number);
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
  printf("Executing pint at line %u\n", line_number);
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

  printf("Executing pop at line %u\n", line_number);
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
  // Implement add operation here
  printf("Executing add at line %u\n", line_number);
}

void nop(stack_t **stack, unsigned int line_number)
{
  // Implement nop operation here
  printf("Executing nop at line %u\n", line_number);
}

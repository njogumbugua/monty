#include "monty.h"
#include "global.h"

/**
 * push - adds an element to top of stack
 * @stack: stack top
 * @line_number: script line being execution
 */

void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *value_str;
	stack_t *new_node;

	if (token[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);

	}
	value_str = token[1];
	new_node = malloc(sizeof(stack_t));
	value = atoi(value_str);
	if (!new_node)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}

	if (!value_str)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
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


/**
 * pall - Print elements in stack
 * @stack: Double linked list
 * @line_number: Script line being executed
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void) line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - Print last node
 * @stack: Double linked list
 * @line_number: Script line being executed
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		printf("%d\n", (*stack)->n);
	} else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - Delete first element
 * @stack: Double linked list
 * @line_number: Script line to be executed
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	top = *stack;
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	*stack = top->next;
	free(top);
}

/**
 * swap - Delete first element
 * @stack: Double linked list
 * @l: Script line to be executed
 */

void swap(stack_t **stack, unsigned int l)
{
	int temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	} else
	{
		fprintf(stderr, "L%u: can't swap, stack has less than two elements\n", l);
		exit(EXIT_FAILURE);
	}
}

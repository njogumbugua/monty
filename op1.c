#include "monty.h"
#include "global.h"

/**
 * push - adds an element to top of stack
 * @stack: stack top
 * @line_number: script line being execution
 * Return: 1 on Success
 */

int push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *value_str;
	stack_t *new_node;

	if (token[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		return (-1);
	}
	value_str = token[1];
	new_node = malloc(sizeof(stack_t));
	value = atoi(value_str);
	if (!new_node)
	{
		perror("Error allocating memory");
		return (-1);
	}

	if (value == 0)
	{
		free(new_node);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		return (-1);
	}
	new_node->prev = NULL;
	new_node->n = value;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
	return (1);
}


/**
 * pall - Print elements in stack
 * @stack: Double linked list
 * @line_number: Script line being executed
 * Return: 1 on Success
 */

int pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void) line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	return (1);
}

/**
 * pint - Print last node
 * @stack: Double linked list
 * @line_number: Script line being executed
 * Return: 1 on Success
 */

int pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		printf("%d\n", (*stack)->n);
	} else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		return (-1);
	}
	return (1);
}

/**
 * pop - Delete first element
 * @stack: Double linked list
 * @line_number: Script line to be executed
 * Return: 1 on Success
 */

int pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	top = *stack;
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		return (-1);
	}

	top = *stack;
	*stack = top->next;
	free(top);
	return (1);
}

/**
 * swap - Delete first element
 * @stack: Double linked list
 * @l: Script line to be executed
 * Return: 1 on Success
 */

int swap(stack_t **stack, unsigned int l)
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
		return (-1);
	}
	return (1);
}

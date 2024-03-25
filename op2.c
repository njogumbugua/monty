#include "main.h"
#include "global.h"

/**
 * add - add the top two elements of the stack
 * @stack: Double linked list
 * @l: Script line to be executed
 */

void add(stack_t **stack, unsigned int l)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		pop(stack, l);
	} else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", l);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop - do nothing
 * @stack: Double linked lists
 * @line_number: Script line to be executed
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtract the top ele from the second top ele
 * @stack: Double linked list
 * @l: Script line to be executed
 */

void sub(stack_t **stack, unsigned int l)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n -= (*stack)->n;
		pop(stack, l);
	} else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", l);
		exit(EXIT_FAILURE);
	}
}

/**
 * _div - divide the second top ele by the top ele
 * @stack: Double linked list
 * @l: Script line to be executed
 */

void _div(stack_t **stack, unsigned int l)
{
	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", l);
			exit(EXIT_FAILURE);
		}
		(*stack)->next->n /= (*stack)->n;
		pop(stack, l);
	} else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", l);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul - mul the top two ele of the stack
 * @stack: Double linked list
 * @l: Script line to be executed
 */

void mul(stack_t **stack, unsigned int l)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n *= (*stack)->n;
		pop(stack, l);
	} else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", l);
		exit(EXIT_FAILURE);
	}
}


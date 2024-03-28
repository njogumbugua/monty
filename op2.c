#include "monty.h"
#include "global.h"

/**
 * add - add the top two elements of the stack
 * @stack: Double linked list
 * @l: Script line to be executed
 * Return: 1 on Success
 */

int add(stack_t **stack, unsigned int l)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		pop(stack, l);
	} else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", l);
		return (-1);
	}
	return (1);
}

/**
 * nop - do nothing
 * @stack: Double linked lists
 * @line_number: Script line to be executed
 * Return: 1 on Success
 */

int nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	return (1);
}

/**
 * sub - subtract the top ele from the second top ele
 * @stack: Double linked list
 * @l: Script line to be executed
 * Return: 1 on Success
 */

int sub(stack_t **stack, unsigned int l)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n -= (*stack)->n;
		pop(stack, l);
	} else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", l);
		return (-1);
	}
	return (1);
}

/**
 * _div - divide the second top ele by the top ele
 * @stack: Double linked list
 * @l: Script line to be executed
 * Return: 1 on Success
 */

int _div(stack_t **stack, unsigned int l)
{
	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", l);
			return (-1);
		}
		(*stack)->next->n /= (*stack)->n;
		pop(stack, l);
	} else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", l);
		return (-1);
	}
	return (1);
}

/**
 * mul - mul the top two ele of the stack
 * @stack: Double linked list
 * @l: Script line to be executed
 * Return: 1 on Success
 */

int mul(stack_t **stack, unsigned int l)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n *= (*stack)->n;
		pop(stack, l);
	} else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", l);
		return (-1);
	}
	return (1);
}


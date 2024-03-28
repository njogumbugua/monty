#include "monty.h"
#include "global.h"

/**
 * mod - modulus of the second top by the top
 * @stack: Double linked list
 * @l: Script line to be executed
 * Return: 1 on Success
 */

int mod(stack_t **stack, unsigned int l)
{
	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", l);
			return (-1);
		}
		(*stack)->next->n %= (*stack)->n;
		pop(stack, l);
	} else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", l);
		return (-1);
	}
	return (1);
}

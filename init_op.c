#include "monty.h"
#include "global.h"

/**
 * init_op - initialize op variable
 * @op: operation variable store functions of monty language
 * Return: None
 */

void init_op(instruction_t *op)
{
	op[0].opcode = "push";
	op[0].f = push;
	op[1].opcode = "pall";
	op[1].f = pall;
	op[2].opcode = "pint";
	op[2].f = pint;
	op[3].opcode = "pop";
	op[3].f = pop;
	op[4].opcode = "swap";
	op[4].f = swap;
	op[5].opcode = "add";
	op[5].f = add;
	op[6].opcode = "nop";
	op[6].f = nop;
	op[7].opcode = "sub";
	op[7].f = sub;
	op[8].opcode = "div";
	op[8].f = _div;
	op[9].opcode = "mul";
	op[9].f = mul;
	op[10].opcode = "mod";
	op[10].f = mod;
	op[11].opcode = "";
	op[11].f = nop;
}

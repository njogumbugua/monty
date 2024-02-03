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

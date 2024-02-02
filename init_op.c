#include "main.h"

void init_op(instruction_t *op)
{
	op[0].opcode = "push";

	op[1].opcode = "pall";

	op[2].opcode = "pint";

	op[3].opcode = "pop";

	op[4].opcode = "swap";

	op[5].opcode = "add";

	op[6].opcode = "nop";


}

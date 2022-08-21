#include "monty.h"
/**
 * get_op - matches op with function
 * @stack - 
 * 
 */
void get_op(stack_t **stack, unsigned int line_number, char *cmd)
{
	instruction_t opp[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"nop", _nop},
		{"swap", _swap},
		{"add", _add},
		{NULL, NULL}
	};

	int i;

	for (i = 0 ; opp[i].f != NULL ; i++)
		if (strcmp(cmd, opp[i].opcode) == 0)
		{
			opp[i].f(stack, line_number);
			return;
		}
}
	

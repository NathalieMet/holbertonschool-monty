#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define DELIMS " \n\t\r"
/**
 * pchar - The opcode pchar prints the char at the top of the stack, followed
 * by a new line.
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current opcode
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *tmp;

	for (tmp = *stack; tmp; tmp = tmp->next)
	{
		fprintf(stdout, "%c\n", tmp->n);
	}

		/*free(tmp);*/

}

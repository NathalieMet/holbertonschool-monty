#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMS " \n\t\r"
/**
 * pint - The opcode pint prints the value at the top of the stack, followed by
 * a new line.
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current opcode
 */
void pint(stack_t **stack, unsigned int line_number)
{

	stack_t *tmp = *stack;

	/*for (tmp = *stack; tmp->next != NULL; tmp = tmp->next);*/

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	fprintf(stdout, "%d\n", tmp->n);


}

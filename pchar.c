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
	stack_t *tmp;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;

	if (tmp->n < 0 || tmp->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%c\n", tmp->n);

}

#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define DELIMS " \n\t\r"
/**
 * pstr - The opcode pstr prints the string starting at the top of the stack,
 * followed by a new line.
 * The string stops when either:
 * the stack is over
 * the value of the element is 0
 * the value of the element is not in the ascii table
 * If the stack is empty, print only a new line
 *
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current opcode
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;


	if ((*stack) == NULL)
	{
		fprintf(stdout, "\n");
		exit(EXIT_SUCCESS);
	}

	tmp = *stack;

	if (tmp->n < 0 || tmp->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (tmp->n != 0 && (*stack) != NULL)
	{
		fprintf(stdout, "%c", tmp->n);
		tmp = tmp->next;
	}
	fprintf(stdout, "\n");
	




}

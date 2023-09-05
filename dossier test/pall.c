#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMS " \n\t\r"
/**
 * pall - print all elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current opcode
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	for (tmp = *stack; tmp; tmp = tmp->next)
		fprintf(stdout, "%d\n", tmp->n);
}

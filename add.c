#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMS " \n\t\r"
/**
 * add - print all elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current opcode
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
		(*stack)->next->n = (*stack)->next->n + temp->n;
		free(temp);
		(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
	}
}

#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMS " \n\t\r"
/**
 * pop - The opcode pop removes the top element of the stack.
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current opcode
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
	}

	if (temp->next == NULL)
	{
		free(temp);
		*stack = (*stack)->next;
	}
	else
	{
	free(temp);
	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;

	}

}

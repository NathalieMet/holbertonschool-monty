#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMS " \n\t\r"
/**
 * fdiv - The opcode div divides the second top element of the stack by the top
 * element of the stack.
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current opcode
 */
void fdiv(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
		(*stack)->next->n = (*stack)->next->n / temp->n;
		(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
		free(temp);
	}
}

#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMS " \n\t\r"
/**
 * swap - print all elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current opcode
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp2 = (*stack)->next;
		(*stack)->next = temp2->next;
		temp2->next = *stack;
		(*stack)->prev = temp2;
		temp2->prev = NULL;
		*stack = temp2;
	}
}

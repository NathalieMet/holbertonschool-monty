#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * free_stack - a function
 * @stack: stack
 * Return: void
 */

void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);

	}
	free(stack);

}

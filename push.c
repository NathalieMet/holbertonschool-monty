#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMS " \n\t\r"

/**
 * push - The opcode push pushes an element to the stack.
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current opcode
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *argument = strtok(NULL, DELIMS);
	int i;

	if (argument == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; argument[i]; i++)
	{
		if (argument[i] == '-' && i == 0)
			continue;
		if (argument[i] < '0' || argument[i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	*stack = create_node(atoi(argument), *stack);
}

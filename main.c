#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMS " \n\t\r"
/**
 * main - Monty interpreter
 * @argc: The number of arguments
 * @argv: The array of arguments
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 *
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL, *opcode;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	instruction_t opcodes[] = {{"push", push}, {"pall", pall}, {"pint", pint},
	{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub},
	{NULL, NULL}};
	int i;

	if (argc != 2)
	{	fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE); }
	file = fopen(argv[1], "r");
	if (file == NULL)
	{	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE); }
	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		opcode = strtok(line, DELIMS);
		if (opcode == NULL || opcode[0] == '#')
			continue;
		for (i = 0; opcodes[i].opcode; i++)
		{
			if (strcmp(opcode, opcodes[i].opcode) == 0)
			{	opcodes[i].f(&stack, line_number);
				break; }
		}
		if (opcodes[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free_stack(stack);
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	free_stack(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}

#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
/**
 * create_node - creates a node
 * @file_value: an int
 * @head: head
 * Return: The new node
 *
 */
stack_t *create_node(int file_value, stack_t *head)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *temp = head;

	if (new_node == NULL)
	{
		free(temp);
		exit(EXIT_FAILURE);
	}

	new_node->n = file_value;

	new_node->next = head;

	new_node->prev = NULL;

	if (head != NULL)
	{
		head->prev = new_node;
	}

	return (new_node);
}

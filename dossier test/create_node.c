#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
/**
 * create_node -
 * @format: The character to print
 *
 * Return: On success 1.
 *
 */
stack_t *create_node (int file_value, stack_t *head)
{
stack_t *new_node = malloc(sizeof(*new_node));
if (new_node == NULL)
exit (EXIT_FAILURE);

new_node->n = file_value;
new_node->next = head;
new_node->prev = NULL;

if (head != NULL)
{
	(head)->prev = new_node;
}

head = new_node;
return(new_node);
}

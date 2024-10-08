#include "monty.h"

/**
 * free_stack - free doubly linked list
 * @head: start of doubly linked list
 */

void free_stack(stack_t *head)
{
	stack_t *cont;

	while (head)
	{
		cont = head;
		head = (*head).next;
		free(cont);
	}
}

#include "monty.h"
#include <stdlib.h>

/**
 * push - adds a new node to the beginning of the linked list
 * @head: beginning of linked list
 * @n: value of new node
 * Return: the new node that was added
 */
stack_t *push(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		if (*head != NULL)
			free_stack(*head);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head)
		(*head)->prev = new_node;

	*head = new_node;

	return (new_node);
}

/**
 * pall - prints doubly linked list
 * @stack: start of doubly linked list
 * @count_n: line number
 */
void pall(stack_t **stack, unsigned int count_n)
{
	stack_t *i = *stack;

	if (!stack)
	{
		fprintf(stderr, "L%d: can't pall, stack empty\n", count_n);
		exit(EXIT_FAILURE);
	}
	for (; i; i = i->next)
		fprintf(stdout, "%d\n", i->n);
}

/**
 * pint - prints first node of linked list
 * @stack: first node of linked list
 * @count_n: line number
 */
void pint(stack_t **stack, unsigned int count_n)
{
	stack_t *i = *stack;

	if (!i)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", count_n);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", i->n);
}

/**
 * pop - removes first node of a linked list
 * @stack: first node of linked list
 * @count_n: line number
 */
void pop(stack_t **stack, unsigned int count_n)
{
	stack_t *rmv = *stack;

	if (!rmv)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count_n);
		exit(EXIT_FAILURE);
	}
	*stack = rmv->next;
	free(rmv);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: first node of linked list
 * @count_n: line number
 */
void swap(stack_t **stack, unsigned int count_n)
{
	int cont = (*stack)->n;

	if (!(stack) || !(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't swap, stack too short\n", count_n);
		exit(EXIT_FAILURE);
	}
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = cont;
}

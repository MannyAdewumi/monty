#include "monty.h"

/**
 * rotl - top element becomes last second becomes top
 * @stack: top of the stack - doubly linked list
 * @count_n: line number
 */
void rotl(stack_t **stack, unsigned int count_n)
{
	stack_t *bottom = *stack, *head = *stack;

	if (count_n)
		count_n = count_n;
	if (head && head->next)
	{
		*stack = head->next;
		(*stack)->prev = NULL;
		for (; bottom->next; bottom = bottom->next)
			;
		bottom->next = head;
		head->next = NULL;
		head->prev = bottom;
	}
}

/**
 * rotr - last element becomes top
 * @stack: top of the stack - doubly linked list
 * @count_n: line number
 */
void rotr(stack_t **stack, unsigned int count_n)
{
	stack_t *bottom = *stack;

	if (count_n)
		count_n = count_n;
	if (*stack && (*stack)->next)
	{
		for (; bottom->next; bottom = bottom->next)
			;
		bottom->prev->next = NULL;
		bottom->prev = NULL;
		bottom->next = *stack;
		(*stack)->prev = bottom;
		*stack = bottom;
	}
}

/**
 * queue - flips the doubly linked list
 * @stack: top of the stack - doubly linked list
 * @count_n: line number
 */
void queue(stack_t **stack, unsigned int count_n)
{
	stack_t *flip = *stack, *cont = *stack;

	if (count_n)
		count_n = count_n;
	if (*stack && ((*stack)->next))
	{
		while (1)
		{
			cont = flip->next;
			flip->next = flip->prev;
			flip->prev = cont;
			if (cont != NULL)
				flip = cont;
			else
				break;
		}

		*stack = flip;
	}
}


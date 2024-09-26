#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: start of doubly linked list
 * @count_n: line number
 */
void add(stack_t **stack, unsigned int count_n)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't add, stack too short\n", count_n);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, count_n);
}

/**
 * sub - subtracts the top two elements of the stack
 * @stack: start of doubly linked list
 * @count_n: line number
 */
void sub(stack_t **stack, unsigned int count_n)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't sub, stack too short\n", count_n);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, count_n);
}
/**
 * divide - divides the top two elements of the stack
 * @stack: start of doubly linked list
 * @count_n: line number
 */
void divide(stack_t **stack, unsigned int count_n)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't div, stack too short\n", count_n);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: division by zero\n", count_n);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	pop(stack, count_n);
}

/**
 * mod - remainder of the top two elements of the stack
 * @stack: start of doubly linked list
 * @count_n: line number
 */
void mod(stack_t **stack, unsigned int count_n)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't mod, stack too short\n", count_n);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: division by zero\n", count_n);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, count_n);
}

/**
 * mul - multiplies the top two elements of the stack
 * @stack: start of doubly linked list
 * @count_n: line number
 */
void mul(stack_t **stack, unsigned int count_n)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't mul, stack too short\n", count_n);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, count_n);
}

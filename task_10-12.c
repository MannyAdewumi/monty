#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Unused.
 * @count_n: Unused.
 */
void nop(stack_t **stack, unsigned int count_n)
{
	(void)*stack;
	(void)count_n;
}

/**
 * pchar - Print the char based on ascii value.
 * @stack: beginning of linked list.
 * @count_n: line number.
 */
void pchar(stack_t **stack, unsigned int count_n)
{
	stack_t *i = *stack;

	if (!i)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count_n);
		exit(EXIT_FAILURE);
	}
	if (!(i->n > 64 && i->n < 91) && !(i->n > 96 && i->n < 123))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count_n);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)i->n);
}

/**
 * pstr - Print string based of ascii values in linked list.
 * @stack: Beginning of linked list.
 * @count_n: Line number.
 */
void pstr(stack_t **stack, unsigned int count_n)
{
	stack_t *i = *stack;
	(void)count_n;

	if (!i)
		printf("\n");
	while (i)
	{
		if (i->n > 127 || i->n <= 0)
		{
			break;
		}
		printf("%c", i->n);
		i = i->next;
	}
}


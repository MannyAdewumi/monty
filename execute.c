#include "monty.h"

/**
 * execute - Split and execute opcode commands
 * @x: Global struct for buffers.
 */
void execute(buf_struct *x)
{
	stack_t *stack = NULL;
	int count_n = 1, i = 0;

	while (x->list_cmd[i])
	{
		split_(x->list_cmd[i], x);
		if (strcmp(x->tok_cmd[0], "push") == 0)
		{
			if (!x->tok_cmd[1] || not_digit(x->tok_cmd[1]) == 0)
				x->tok_cmd[1] = "r";
			if ((strcmp(x->tok_cmd[1], "0") != 0 && atoi(x->tok_cmd[1]) == 0))
			{
				free_stack(stack);
				fprintf(stderr, "L%d: usage: push integer\n", count_n);
				exit(EXIT_FAILURE);
			}
			else
				push(&stack, atoi(x->tok_cmd[1]));
		}
		else
		{
			if (get_op_func(x->tok_cmd[0]) == NULL)
			{
				free(stack);
				fprintf(stderr, "L%d: unknown instruction %s\n", count_n, x->tok_cmd[0]);
				exit(EXIT_FAILURE);
			}
			(*get_op_func(x->tok_cmd[0]))(&stack, count_n);
		}
		count_n++;
		i++;
	}
	free_stack(stack);
}

/**
 * get_op_func - selects the correct function to perform
 * @s: name of function
 * Return: pointer to function
 */
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t cmd[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divide},
		{"mod", mod},
		{"mul", mul},
		{"nop", nop},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"queue", queue},
		{"stack", queue},
		{NULL, NULL}};
	int i = 0;

	while (cmd[i].opcode)
	{
		if (strcmp(s, cmd[i].opcode) == 0)
		{
			return (cmd[i].f);
		}
		i++;
	}
	return (NULL);
}


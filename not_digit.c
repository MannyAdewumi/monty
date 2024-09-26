#include "monty.h"

/**
 * not_digit - checks for non integer types in a string
 * @str: string to check
 * Return: 0 if it contains non integer type 1 if only integer type
 */
int not_digit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		if (isdigit(str[i]) == 0)
		{
			if (str[i] == '-' && i == 0)
				continue;
			return (0);
		}
	return (1);
}


#include "monty.h"
/**
 * split_line - Tokenizes read buffer on newlines.
 * @x: Global struct for buffers.
 * Return: Tokenized list of commands.
 */
char **split_line(buf_struct *x)
{
	char del[] = "\n";
	char *tok;
	int i = 0;

	tok = strtok(x->read_buff, del);

	while (tok != NULL)
	{
		x->list_cmd[i] = tok;
		tok = strtok(NULL, del);
		i++;
	}
	if (x->list_cmd[0] == NULL)
		return (NULL);
	return (x->list_cmd);
}
/**
 * split_ - Tokenize each command from its value.
 * @buff: Index from first tokenized list of commands.
 * @x: Global struct for buffers.
 * Return: Tokenized command.
 */
char **split_(char *buff, buf_struct *x)
{
	char del[] = " \t";
	char *tok;
	int i = 0;

	tok = strtok(buff, del);
	while (tok != NULL && i < 2)
	{
		x->tok_cmd[i] = tok;
		tok = strtok(NULL, del);
		i++;
	}
	x->tok_cmd[i] = NULL;
	if (x->tok_cmd[0] == NULL)
		return (NULL);
	if (strncmp(x->tok_cmd[0], "#", 1) == 0)
		x->tok_cmd[0] = "nop";
	return (x->tok_cmd);
}


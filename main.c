#include "monty.h"
/**
 * make_struct - Set values for struct.
 * @argv: Argument list.
 * Return: Struct for buffers.
 */
buf_struct *make_struct(char *argv[])
{
	static buf_struct x;

	x.argv = argv;
	memset(x.read_buff, 0, sizeof(x.read_buff));
	memset(x.list_cmd, 0, sizeof(x.list_cmd));
	memset(x.tok_cmd, 0, sizeof(x.tok_cmd));

	return (&x);
}
/**
 * main - Takes argument list and executes file given.
 * @argc: Argument count.
 * @argv: List of arguments.
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	int file;
	buf_struct *x;

	x = make_struct(argv);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	while ((file = open(argv[1], O_RDONLY)) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read(file, x->read_buff, 4096);
	close(file);
	split_line(x);
	execute(x);

	return (0);
}


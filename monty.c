#include "monty.h"

/**
 * main - entry programming for programme
 * @ac: command line arguments for number of args
 * @av: array of arguments from the command line
 * Return: always 0
 */
int main(int ac, char *av[])
{
	stack_t *stack = NULL;
	int n = 0;
	FILE *fd;
	size_t bufsize = 1000;
	static char *string[1000] = {NULL};


	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&(string[n]), &bufsize, fd) > 0)
		n++;
	op_instruct(string, stack);
	_free(string);
	fclose(fd);
	return (0);
}

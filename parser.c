#include "monty.h"

/**
 * op_instruct - executes opcode instructions
 * @string: contents of file
 * @stack: list
 */
void op_instruct(char *string[], stack_t *stack)
{
	int line_no, i, n;

	instruction_t st[] = {
		{"pall", pall},
		{"swap", swap},
		{"pop", pop},
		{"null", NULL}
	};
	for (line_no = 1, n = 0; string[n + 1]; n++, line_no++)
	{
		if (_strcmp("push", string[n]))
			push(&stack, line_no, pushint(string[n], line_no));
		else if (_strcmp("nop", string[n]))
			;
		else
		{
			i = 0;
			while (!_strcmp(st[i].opcode, "null"))
			{
				if (_strcmp(st[i].opcode, string[n]))
				{
					st[i].f(&stack, line_no);
					break;
				}
				i++;
			}
			if (_strcmp(st[i].opcode, "null") && !_strcmp(string[n], "\n"))
			{
				fprintf(stderr, "L%u: unknown instruction %s", line_no, string[n]);
				if (!find_newline(string[n]))
					fprintf(stderr, "\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	free_stack(stack);
}

/**
 * _strcmp - compares strings
 * @opcode: string to be compared
 * @list: string to be compared
 * Return: 0
 */
int _strcmp(char *opcode, char *list)
{
	while (*list)
	{
		if (*list == ' ')
		{
			opcode++;
			list++;
			if (*opcode == '\0' && (*list == ' ' || *list == '\n' || *list == '\0'))
				return (1);
		}
		else
			return (0);
	}
	return (0);
}

/**
 * find_newline - finds newline
 * @list: the string to check
 * Return: 1 or 0
 */
int find_newline(char *list)
{
	char *opcode = "\n";

	while (*list)
	{
		if (*opcode == *list)
		{
			opcode++;
			list++;
			if (*opcode == '\0')
				return (1);
		}
		else
			list++;
	}
	return (0);
}

/**
 * pushint - int for push opcode
 * @list: the content of the file
 * @line_no: line number
 * Return: the number
 */
int pushint(char *list, int line_no)
{
	char *opcode = "push";

	while (*list)
	{
		if (*opcode == *list)
		{
			opcode++;
			list++;
			if (*opcode == '\0')
				while (*list)
				{
					if ((*list >= '0' && *list <= '9') || *list == '-')
					{
						combfind(list, line_no);
						return (atoi(list));
					}
					else if (*list == ' ')
						list++;
					else
					{
						fprintf(stderr, "L%d: usage: push integer\n", line_no);
						exit(EXIT_FAILURE);
					}
				}
		}
		else
			list++;
	}
	return (0);
}

/**
 * combfind - finds non-numbers and number combinations
 * @list: string to check
 * @line_no: number of lines
 * Return: 1
 */
int combfind(char *list, int line_no)
{
	int i = 1;

	while (list[i])
	{
		if (list[i] == '\0' || list[i] == '\n')
			break;
		if ((list[i] >= '0' && list[i] <= '9') || list[i] == ' ')
			i++;
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_no);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

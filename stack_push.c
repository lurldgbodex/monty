#include "monty.h"

/**
 * push - pushes an element to the stack
 * @para - element to push to stack
 */
void push(int para)
{
	prev = NULL;
	stact_t *new_node;
	if (!para || !atoi(para))
	{
		printf("L<line_number>: usage: push integer");
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		exit(1);
	new_node->n = i;
	new_node->next = prev;
	prev = new_node;
}

/**
 * pall - prints all the values of the stack
 */
void pall()
{
	stack_t *temp;
	temp = prev
	if (!prev)
		return;
	else
	{
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}


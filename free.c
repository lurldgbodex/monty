#include "monty.h"

/**
 * free_stack - frees linked list
 * @head: pointer to list
 */
void free_stack(stack_t *head)
{
	stack_t *link = head;

	if (!head)
		return;

	while (head)
	{
		link = head;
		head = head->next;
		free(link);
	}
}

/**
 * _free - frees list
 * @a: pointer to array of strings
 */
void _free(char *a[])
{
	int i = 0;

	while (a[i])
	{
		free(a[i]);
		i++;
	}
}

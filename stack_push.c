#include "monty.h"
#include <stdio.h>

/**
 * push - pushes an element to the stack
 * @para - element to push to stack
 */
void push(int para, unsigned int line_num)
{
	head = NULL;
	stact_t *new_node;
	if (!para)
	{
		fprintf(stderr, "L%d: usage: push integer", lin_num);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->n = para;
	new_node->next = head;
	head = new_node;
}

/**
 * pall - prints all the values of the stack
 */
void pall()
{
	stack_t *temp;
	temp = head
	
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


#include "monty.h"
#include <stdio.h>

/**
 * push - pushes an element to the stack
 * @stack: ponter to head of stack
 * @line_number: number of line in files
 * @data: data to push to stack
 */
void push(stack_t **stack, unsigned int line_number, int data)
{
	stack_t *head = *stack;
	stack_t *new_node;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));

	if (!new_node)
		exit(EXIT_FAILURE);
	new_node->prev = NULL;
	new_node->n = data;
	new_node->next = *stack;
	if (*stack)
		head->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all the values of the stack
 * @stack: pointer to head of stack node
 * @line_number: number of lines in file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *temp = *stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop - removes the top element in a stack
 * @stack: pointer to the head of stack
 * @line_number: number of lines in a file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (head)
	{
		*stack = head->next;
		free(head);
	}
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the head of the stack node
 * @line_number: number of lines in a file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *temp;

	if (!(*stack) || (!(*stack)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (head && head->next)
	{
		temp = head->next;
		if (temp->next)
			temp->next->prev = head;
		head->next = temp->next;
		temp->prev = NULL;
		temp->next = head;
		head->prev = temp;
		*stack = temp;
	}
}

#include "monty.h"

/**
 * len - finds the length of the stack
 * @stack: target stack
 *
 * Return: length of stack
 */
unsigned int len(stack_t **stack)
{
	stack_t *current;
	unsigned int l = 0;

	current = *stack;
	while (current)
	{
		current = current->next;
		l++;
	}
	return (l);
}

/**
 * free_stack - frees stack from memory
 * @stack: target stack
 *
 * Return: none
 */

void free_stack(stack_t *stack)
{
	stack_t *next;

	while (stack != NULL)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

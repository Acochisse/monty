#include "monty.h"
/**
*pall - function to print stack's elements
*@line_number: unused, line position of command, refers to all prev lines
*@stack: target stack
*Return: None
*/

void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *current = *stack;

	if (stack == NULL || *stack == NULL)
		return;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
*pint - print the int at the top
*@stack: target stack
*@line_number: line position of command in monty file
*Return: nothing
*/
void pint(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 *nop - function to do nothing
 *@stack: target stack
 *@line_number: line position of command in monty file
 *Return: nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	return;
}

#include "monty.h"

/**
 * _add - adds top two elements and replaces them with the sum
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: none excecpt -1 on fail
 */

void _add(stack_t **stack, unsigned int line_number)
{

	int i, j, ret;
	stack_t *current = *stack;

	if (len(stack) < 2)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	i = current->n;
	j = current->next->n;

	ret = (i + j);
	current->next->n = ret;
	*stack = current->next;
	free(current);


}

/**
 * _sub - subracts top two elements and replaces them with the sum
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: none excecpt -1 on fail
 */

void _sub(stack_t **stack, unsigned int line_number)
{

	int i, j, ret;
	stack_t *current = *stack;

	if (len(stack) < 2)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	i = current->n;
	j = current->next->n;

	ret = (j - i);
	current->next->n = ret;
	*stack = current->next;
	free(current);


}

/**
 * _mul - multiples top two elements and replaces them with the sum
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: none excecpt -1 on fail
 */

void _mul(stack_t **stack, unsigned int line_number)
{

	int i, j, ret;
	stack_t *current = *stack;

	if (len(stack) < 2)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	i = current->n;
	j = current->next->n;

	ret = (i * j);
	current->next->n = ret;
	*stack = current->next;
	free(current);


}

/**
 * _div - divide top two elements and replaces them with the sum
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: none excecpt -1 on fail
 */

void _div(stack_t **stack, unsigned int line_number)
{

	int i, j, ret;
	stack_t *current = *stack;

	if (len(stack) < 2)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	i = current->n;
	j = current->next->n;

	ret = (j / i);

	current->next->n = ret;
	*stack = current->next;
	free(current);

}

/**
 * _mod - modulo top two elements and replaces them with the sum
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: none excecpt -1 on fail
 */

void _mod(stack_t **stack, unsigned int line_number)
{

	int i, j, ret;
	stack_t *current = *stack;

	if (len(stack) < 2)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	i = current->n;
	j = current->next->n;

	ret = (j % i);

	current->next->n = ret;
	*stack = current->next;
	free(current);

}

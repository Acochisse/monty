#include "monty.h"

/**
*push - adds a value at top of stack
*@stack: target struct
*@line_number: input line in monty file
*Return: none
*/
void push(stack_t **stack, char *n, unsigned int line_number)
{
	stack_t *new = NULL;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (n == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; n[i]; i++)
	{
		if (n[0] == '-' && i == 0)
			continue;
		if (n[i] < 48 || n[i] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	new->n = atoi(n);
	new->prev = NULL;
	new->next = NULL;
	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}

/**
 *pop - removes top element and replaces
 *@line_number: line position of commmand in monty file
 *@stack: target stack
 *Return: none
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *to_the_end;

	if (stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if (*stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		to_the_end = *stack;
		*stack = (*stack)->next;
		free(to_the_end);
	}
}

/**
* swap - swaps the value of the top two elements to the stack
* @stack: target stack
* @line_number: line position of command in monty file
* Return: void, exit with -1 on failure
**/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
	free(temp);
}

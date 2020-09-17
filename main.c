#include "monty.h"


/**
* opcode_finder - find opcode
* @stack: target stack
* @opcode: read line opcode
* @line_number: line number
* Return: 1 on success or stderr
**/
int find_opcode(stack_t **stack, char *opcode, int line_number)
{
	instruction_t opcodes[] = {
		{"pall", pall},
		{"pop", pop},
		{"swap", swap},
		{"pint", pint},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"nop", nop},
		{NULL, NULL}
	};

	int i;

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			(opcodes[i].f)(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}


/**
* main - Parses input monty file into args and opcode
* @argc: arg count
* @argv: arg vector
* Return: EXIT_SUCCESS, or EXIT_FAILURE on fail
**/

int main(__attribute__((unused)) int argc, char const *argv[])
{
	FILE *montyf;
	char *buff = NULL, *opcode, *n;
	size_t line = 0;
	int line_number = 0;
	stack_t *stack = NULL, *current;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	montyf = fopen(argv[1], "r");
	if (montyf == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(1);
	}
	while ((getline(&buff, &line, montyf)) != -1)
	{
		line_number++;
		opcode = strtok(buff, DELIMINATOR);
		if (opcode == NULL || opcode[0] == '#')
			continue;
		if (!strcmp(opcode, "nop"))
			continue;
		else if (!strcmp(opcode, "push"))
		{
			n = strtok(NULL, DELIMINATOR);
			push(&stack, n, line_number);
		}
		else
			find_opcode(&stack, opcode, line_number);
	}
	fclose(montyf);
	free(buff);
	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
	return (0);
}

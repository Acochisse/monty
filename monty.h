#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "aux.h"

#define DELIMINATOR "\n\t\r "


/* opcodes */
extern instruction_t opcodes[];

/* stack functions */
void push(stack_t **stack, char *n, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/* print functions */
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

/* math functions */
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);

/* util functions */
unsigned int stack_length(stack_t **stack);
int find_opcode(stack_t **stack, char *opcode, int line_number);
void free_stack(stack_t *stack);
unsigned int len(stack_t **stack);



#endif

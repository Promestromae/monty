#include "monty.h"

/**
 * _pstr - function that checks for alpha
 * @stack: double pointer to lists for monty stack
 * @line_number: number of the line that opcode occurs in
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int c = 0;

	(void)line_number;


	while (tmp)
	{
		c = tmp->n;
		if (c == 0 || _isalpha(c) == 0)
			break;
		putchar(c);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * _rotl - function that computes the rest of the division
 * of the second top element of the stack by the top element of the stack
 * @stack: double pointer to lists for monty stack
 * @line_number: number of the line that opcode occurs on
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;


	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	aux1 = runner->n;

	while (runner->next)
	{
		runner = runner->next;
		runner->prev->n = runner->n;
	}

	runner->n = aux1;
}

/**
 * _rotr - function that rotates the stack to the top.
 * @stack: double pointer to lists for monty stack
 * @line_number: number of line that opcode occurs on
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;

	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (runner->next)
		runner = runner->next;

	aux1 = runner->n;

	while (runner->prev)
	{
		runner = runner->prev;
		runner->next->n = runner->n;
	}

	runner->n = aux1;
}

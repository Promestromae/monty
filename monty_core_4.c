#include "monty.h"

/**
 * _mod - function that computes the rest of the division
 * of the second top element of the stack by the top element of the stack.
 * @stack: double pointer to lists for the stack
 * @line_number: line number opcode appears in
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int mod = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		mod = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n %= mod;
	}
}
/**
 * _sub - funvction that subtracts the top element of the stack
 * from the second top element of the stack
 * @stack: double pointer to the stack
 * @line_number: line number opcode occurs in
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int sub = 0, i = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = sub;
}

/**
 * _div - function that divides the second top element of the stack
 * by the top element of the stack.
 * @stack: double pointer to the stack
 * @line_number: line number to opcode occurs
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int div = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		div = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n /= div;
	}
}
/**
 * _mul - function multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: double pointer to lists of the stack
 * @line_number: line number the opcode occurs in
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		aux = (*stack)->n;
		_pop(stack, line_number);
		(*stack)->n *= aux;
	}
}

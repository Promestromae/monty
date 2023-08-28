#include "monty.h"
/**
 * _push - function that pushes int to a stack
 * @stack: double pointer to monty stack
 * @line_number: number of line the opcode occurs on
 */
void _push(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = var_global.push_arg;
	if (var_global.mode == 0)
	{
		top->next = *stack;
		top->prev = NULL;
		if (*stack != NULL)
			(*stack)->prev = top;
		*stack = top;
	}
	else if (var_global.mode == 1)
	{
		top->next = NULL;
		if (*stack == NULL)
		{
			top->prev = NULL;
			*stack = top;
		}
		else
		{
			top->prev = get_tail(*stack);
			top->prev->next = top;
		}
	}
}

/**
 * _pall - function that prints all functions inputed
 * @stack: double pointer to the linked list stack
 * @line_number: number of lines the opcode occurs on
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	while (runner != NULL)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}

/**
 * _pint - function that prints int at top of stack
 * @stack: double pointer to linked list stack
 * @line_number: the number of line opcode occurs in
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	if (runner == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runner->n);
}

/**
 * _pop - function that removes element in a list
 *@stack: double pointer to first node of the stack
 *@line_number: line number the opcode appears
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *nodo = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = nodo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(nodo);
}

/**
 * free_dlistint - function that frees a list
 * @head: pointer to first node of the stack
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

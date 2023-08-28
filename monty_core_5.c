#include "monty.h"

/**
 * _stack - function that sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the head stack
 * @line_number: line indx of the opcode in the file
 */

void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	var_global.mode = 0;
}

/**
 * _queue - function that sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the stack
 * @line_number: line indx of the opcode in the file
 */

void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	var_global.mode = 1;
}

/**
 * get_tail - function that returns a pointer to the last node of the queue
 * @stack: double pointer to the head of the queues
 * Return: pointer to the last node, NULL if empty
 */

stack_t *get_tail(stack_t *stack)
{
	stack_t *tail;

	if (stack == NULL)
		return (NULL);

	tail = stack;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}

	return (tail);
}

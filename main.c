#include "monty.h"
global_var var_global;
/**
 * main - function that drives monty program
 * @ac: number of the arguments passed
 * @av: opcode argument file
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(av[1], &stack);

	free_dlistint(stack);
	return (0);
}

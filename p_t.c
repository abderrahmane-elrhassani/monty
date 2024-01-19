#include "monty.h"

/**
 *p_t - Prints the value at the top of the stack.
 *@stack: Double pointer to the stack head.
 *@line_number: Script line number.
 *Usage: print
 *If the stack is empty, print error L<line_number>: can't pint, stack empty
 *and exit with EXIT_FAILURE
 *Return: No return.
 */

void p_t(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

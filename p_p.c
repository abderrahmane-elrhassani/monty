#include "monty.h"

/**
 *p_p - Removes the top element from the stack.
 *@stack: Double pointer to the stack head.
 *@line_number: Script line number.
 *If the stack is empty,print error L<line_number>: can't pop an empty stack
 *and exit with EXIT_FAILURE.
 *Return: No return.
 */


void p_p(stack_t **stack, unsigned int line_number)
{
	stack_t *popped;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	popped  = *stack;
	(*stack) = (*stack)->next;
	free(popped);
}

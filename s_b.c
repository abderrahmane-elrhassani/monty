#include "monty.h"

/**
 *s_b - Subtracts the top element of the stack from the second top element.
 *@stack: Double pointer to the stack head.
 *@line_number: Script line number.
 *Usage: sub
 *If stack has less than two elements, print error L<line_number>: can't sub *, stack too short
 *and exit with EXIT_FAILURE.
 *Result is stored in the second top element, and top element is removed.
 *Return: No return.
 */

void s_b(stack_t **stack, unsigned int line_number)
{
	int temp_variable;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp_variable = (*stack)->n;
	p_p(stack, line_number);
	(*stack)->n -= temp_variable;
}

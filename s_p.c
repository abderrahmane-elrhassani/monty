#include "monty.h"

/**
 *s_p  - Swaps the top two elements of the stack.
 *@stack: Double pointer to the stack head.
 *@line_number: Script line number.
 *Usage: swap
 *If stack has less than two elements, print error L<line_number>:
 *can't swap, stack too short
 *and exit with EXIT_FAILURE.
 *Return: No return.
 */

void s_p(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_variable;

	(void)(line_number);
	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp_variable = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = temp_variable->next;
	temp_variable->prev = NULL;
	(*stack)->prev = temp_variable;
	if (temp_variable->next)
		temp_variable->next->prev = *stack;
	temp_variable->next = *stack;
	(*stack) = (*stack)->prev;
}

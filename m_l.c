#include "monty.h"

/**

*m_d - Multiplies the second top element of the stack with the top element.
*@stack: Double pointer to the stack head.
*@line_number: Script line number.
*Usage: mod
*If stack has less than two elements, print error L<line_number>: can't mod,*stack too short
*and exit with EXIT_FAILURE.
*Result is stored in second top element, and top element is removed.
*If top element is 0, print error L<line_number>: division by zero and exit *with EXIT_FAILURE.
*Return: No return.

*/

void m_l(stack_t **stack, unsigned int line_number)
{
	int temp_variable;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp_variable = (*stack)->n;
	p_p(stack, line_number);
	(*stack)->n *= temp_variable;
}

#include "monty.h"

/**
 *pc_r - function that multiplies the second top element of the stack,
 *with the top element of the stack.
 *@stack: double pointer to the head of stack.
 *@line_number: script line number.
 *Usage: mul .
 *If the stack contains less than two elements, print the error message,
 * L<line_number>: can't mul, stack too short, followed by a new line,
 *and exit with the status EXIT_FAILURE .
 *The result is stored in the second top element of the stack, and the,
 *top element is removed, so that at the end: The top element of the,
 *stack contains the result and the stack is one element shorter
 * Return: no return
 */
void pc_r(stack_t **stack, unsigned int line_number)
{
	int ch;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	ch = (*stack)->n;
	if (!isascii(ch))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ch);
}



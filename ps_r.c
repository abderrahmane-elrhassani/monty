#include "monty.h"

/**
 *ps_r- Prints the string starting at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Script line number.
 *
 * The integer stored at the top of the stack is treated as the ASCII
 * value of the character to be printed. The string stops when either:
 * the stack is over, the value of the element is 0, or the value of
 * the element is not in the ASCII table. If the stack is empty, print
 * only a new line.
 */
void  ps_r(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_variable = *stack;

	(void)(line_number);

	if (!temp_variable)
	{
		printf("\n");
		return;
	}

	while (temp_variable && isascii(temp_variable->n) && temp_variable->n != 0)
	{
		putchar(temp_variable->n);
		temp_variable = temp_variable->next;
	}

	putchar('\n');
}

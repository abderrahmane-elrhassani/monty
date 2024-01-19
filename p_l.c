#include "monty.h"

/**
 *p_l - Prints all values on the stack from the top.
 *@stack: Double pointer to the stack head.
 *@line_number: Script line number.
 *If the stack is empty, no output is printed.
 *Return: No return.

*/

void p_l(stack_t **stack, unsigned int line_number)
{
	stack_t *element = *stack;

	(void)(line_number);
	while (element != NULL)
	{
		printf("%d\n", element->n);
		element = element->next;
	}
}

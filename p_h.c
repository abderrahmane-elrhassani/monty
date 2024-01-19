#include "monty.h"

/**
 *p_h - Pushes an integer element onto the stack.
 *@stack: Double pointer to the stack head.
 *@line_number: Script line number.
 *Usage: push <int>
 *If <int> is not an integer or no argument is given, print error
 *L<line_number>: usage: push integer and exit with EXIT_FAILURE.
 *Note: No need to handle overflows; use the atoi function
 *Return: No return.
 */

void p_h(stack_t **stack, unsigned int line_number)
{
	stack_t *element = malloc(sizeof(stack_t));
	char *opcode;
	int num;

	if (!element)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	opcode = strtok(NULL, "\n\t\r ");
	if (opcode == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = interpreter(opcode, line_number);
	element->n = num;
	element->prev = NULL;
	element->next = *stack;
	if (element->next != NULL)
		(element->next)->prev = element;
	*stack = element;
}

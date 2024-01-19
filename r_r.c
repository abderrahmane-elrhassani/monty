#include "monty.h"

/**
 * r_r - Function that rotates the stack to the bottom.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Script line number.
 *
 * Description: The last element of the stack becomes the first one.
 * The _rotr function never fails.
 *
 * Return: No return value.
 */

void r_r(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_variable = *stack;

	(void)(line_number);
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (temp_variable->next != NULL)
		temp_variable = temp_variable->next;
	temp_variable->next = *stack;
	temp_variable->prev->next = NULL;
	temp_variable->prev = NULL;
	(*stack)->prev = temp_variable;
	(*stack) = temp_variable;
}

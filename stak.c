#include "monty.h"

/**
 * _stack - Sets the format of the data to a stack (LIFO).
 * @stack: Double pointer to the head of the stack.
 * @line_number: Script line number.
 *
 * Description: This function sets the format of the data to a stack (LIFO).
 * It updates the global variable 'var.queue' to indicate stack mode.
 * No stack operations are performed in this function.
 */
void _stack(stack_t **stack, unsigned int line_number)
{
    (void)(stack);
    (void)(line_number);
    var.queue = STACK;
}

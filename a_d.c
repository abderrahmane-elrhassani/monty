#include "monty.h"

/**

*a_d - Adds the top two elements of the stack.
*@stack: Double pointer to the stack head.
*@line_number: Line number in the script.
*Usage: add
*If stack has less than two elements,print error L<line_number>: can't *swap, stack too short
*and exit with EXIT_FAILURE.
*Result is stored in second top element, and top element is removed.
*The stack is one element shorter at the end.
*Return: No return.
*/

void a_d(stack_t **stack, unsigned int line_number)
{
        int temp_variable;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

        temp_variable = (*stack)->n;
        p_p(stack, line_number);
        (*stack)->n += temp_variable;
}

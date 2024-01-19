#include "monty.h"

/**

*d_v - Divides the second top element of the stack by the top element.
*@stack: Double pointer to the stack head.
*@line_number: Line number in the script.
*Usage: div
*If stack has less than two elements, print error L<line_number>: can't div,*stack too short
*and exit with EXIT_FAILURE.
*Result is stored in second top element, and top element is removed.
*If top element is 0, print error L<line_number>: division by zero and exit *with EXIT_FAILURE.
*Return: No return.
*/

void d_v(stack_t **stack, unsigned int line_number)
{
        int temp_variable;

        if (!(*stack) || !(*stack)->next)
        {
                fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        temp_variable = (*stack)->n;
        if (temp_variable == 0)
        {
                fprintf(stderr, "L%u: division by zero\n", line_number);
                exit(EXIT_FAILURE);
        }
        p_p(stack, line_number);
        (*stack)->n /= temp_variable;
}

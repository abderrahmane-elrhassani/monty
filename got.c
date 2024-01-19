#include "monty.h"

/**
 * got - Checks opcodes against valid opcodes.
 * @stack: Double pointer to stack head.
 * @op: Pointer to opcode.
 * @line_number: Script line number.
 * Return: No return.
 */
void got(stack_t **stack, char *op, unsigned int line_number)
{
    int i = 0;
    instruction_t valid_opcodes[] = {
        {"push", p_h}, {"pchar", pc_r},
        {"pall", p_l}, {"pstr", ps_r},
        {"pint", p_t}, /*{"rotl", r_l},*/
        {"pop", p_p},/* {"rotr", r_r},*/
        {"swap", s_p},/* {"queue", que},*/
        {"add", a_d},/* {"stack", stak},*/
        {"nop", n_p},
        {"sub", s_b},
        {"div", d_v},
        {"mul", m_l},
        {"mod", m_d},
        {NULL, NULL}};

    for (i = 0; valid_opcodes[i].opcode; i++)
    {
        if (strcmp(op, valid_opcodes[i].opcode) == 0)
        {
            valid_opcodes[i].f(stack, line_number);
            return;
        }
    }
    if (strlen(op) != 0 && op[0] != '#')
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
        exit(EXIT_FAILURE);
    }
}

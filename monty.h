#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO in Holberton project.
 */

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its corresponding function
 * @opcode: The opcode
 * @f: Function to handle the opcode
 *
 * Description: Opcode and its function
 * for stack, queues, LIFO, FIFO in Holberton project.
 */

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_vars - Globally useful variables rolled into one.
 * @top: Double pointer to the top of the stack.
 * @ops: Double pointer to an instruction struct.
 */

typedef struct global_vars
{
    stack_t **top;
    instruction_t **ops;
} glob_vars;

extern glob_vars globv;

/**
 * struct var_s - Struct to contain the main variables of the Monty interpreter.
 * @queue: Flag to determine if in stack vs queue mode.
 * @stack_len: Length of the stack
 */

typedef struct var_s
{
    int queue;
    size_t stack_len;
} var_t;

extern var_t var;

#define STACK 0
#define QUEUE 1

void s_i(stack_t **head);
void f_a(void);
int f_r(char *filename, stack_t **stack);
void got(stack_t **stack, char *op, unsigned int line_number);
void p_h(stack_t **stack, unsigned int line_number);
void p_l(stack_t **stack, unsigned int line_number);
int interpreter(char *num_string, unsigned int line_number);
void p_t(stack_t **stack, unsigned int line_number);
void p_p(stack_t **stack, unsigned int line_number);
void s_p(stack_t **stack, unsigned int line_number);
void a_d(stack_t **stack, unsigned int line_number);
void n_p(stack_t **stack, unsigned int line_number);
void s_b(stack_t **stack, unsigned int line_number);
void d_v(stack_t **stack, unsigned int line_number);
void m_l(stack_t **stack, unsigned int line_number);
void m_d(stack_t **stack, unsigned int line_number);
void pc_r(stack_t **stack, unsigned int line_number);
void ps_r(stack_t **stack, unsigned int line_number);
/*void r_l(stack_t **stack, unsigned int line_number);
void r_r(stack_t **stack, unsigned int line_number);
void stak(stack_t **stack, unsigned int line_number);
void que(stack_t **stack, unsigned int line_number);
*/
#endif /* MONTY_H */

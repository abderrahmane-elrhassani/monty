#include "monty.h"

glob_vars globv;

/**
 * main - Entry point for Monty bytecode interpreter.
 * @ac: Number of command line arguments.
 * @av: Pointer to array containing command line arguments.
 *
 * Usage: monty file
 * If no file or more than one argument is given, print error USAGE: monty file
 * and exit with EXIT_FAILURE.
 * If unable to open the file, print error Error: Can't open file <file>
 * and exit with EXIT_FAILURE where <file> is the name of the file.
 * If the file contains an invalid instruction, print error L<line_number>: unknown instruction <opcode>
 * and exit with EXIT_FAILURE, where <line_number> is the line number where the instruction appears.
 * If malloc fails, print error Error: malloc failed and exit with EXIT_FAILURE.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    stack_t *head;

    s_i(&head);
    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    f_r(av[1], &head);
    exit(EXIT_SUCCESS);
}

/**
 * f_r - Processes the entire Monty opcode file.
 * @filename: String name of the Monty opcode file.
 * @stack: Double pointer to the top of the stack data structure.
 * Return: Returns an error code or success.
 **/
int f_r(char *filename, stack_t **stack)
{
   size_t len;
	ssize_t read;
	unsigned int line_number = 0;
	char *line = NULL;
	FILE *fp;
	char *op;


	if (!filename)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	atexit(f_a);
	while ((read = getline(&line, &len, fp)) != -1)
	{
		op = strtok(line, "\n\t\r ");
		line_number++;
		if (op)
			got(stack, op, line_number);
	}
	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
 /* Function implementation...*/
}

/**
 * s_i - Initializes all the necessary elements.
 * @head: Double pointer to the top of the stack.
 *
 * Return: No return.
 **/
void s_i(stack_t **head)
{
    *head = NULL;
    globv.top = head;
}

/**
 * f_a - Frees all dynamically allocated memory.
 *
 * Return: No return.
 **/
void f_a(void)
{
    stack_t *tmp1, *tmp2 = NULL;

    tmp1 = *(globv.top);
    while (tmp1 != NULL)
    {
        tmp2 = tmp1->next;
        free(tmp1);
        tmp1 = tmp2;
    }
}

#include "monty.h"

/**

*interpreter - Wrapper around strtol, handling Monty-specific errors.
*@num_string: String that should represent an integer.
*@line_number: Line counter of Monty file.
*Return: Long int that strtol converted.

*/

int interpreter(char *num_string, unsigned int line_number)
{
	int base = 10;
	char *endptr;
	long val;


	errno = 0;    
	val = strtol(num_string, &endptr, base);

	if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN))
									|| (errno != 0 && val == 0))
	{
		exit(EXIT_FAILURE);
	}

	if (endptr == num_string)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (num_string[0] != '\0')
		if (!isdigit(num_string[0]) && *endptr != '\0')

		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	return (val)
}

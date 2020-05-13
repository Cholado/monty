#include "monty.h"

/**
 * isdigits - checks if every char in a  string is a digit
 * @str: pointer to string to check
 *
 * Return: 1 if all digits, 0 if not
 */
int isdigits(char *str)
{
	if (*str == '-')
	{
		str++;
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	while (*str != 0)
		if (*str < '0' || *str++ > '9')
			return (0);
	return (1);
}

#include "monty.h"

/**
 * pint -  prints the value at the top of the stack, followed by a new line.
 * @head: pointer to first element position of stack
 * Desciption: pint stands for print integer
 * Return: void
 */
void pint(stack_t **head)
{
	if (*head == NULL)
		end_process(EXIT_FAILURE, "can't pint, stack empty", *head);
	printf("%d\n", (*head)->n);
}

#include "monty.h"

/**
 * pchar -  prints char @ first element of the stack, followed by a new line.
 *
 * @head: pointer to first element of stack
 * Return: void
 */
void pchar(stack_t **head)
{
	stack_t *ptr = *head;

	if (ptr == NULL)
		end_process(EXIT_FAILURE, "can't pchar, stack empty", *head);
	if (ptr->n > 127 || ptr->n < 0)
		end_process(EXIT_FAILURE, "can't pchar, value out of range", *head);
	printf("%c\n", ptr->n);
}

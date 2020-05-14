#include "monty.h"

/**
 * pstr -  prints string starting at first element of the stack
 * followed by a new line.
 * @head: pointer to first element of stack
 * Return: void
 */
void pstr(stack_t **head)
{
	stack_t *ptr = *head;

	while (ptr != NULL && ptr->n <= 127 && ptr->n > 0)
	{
		printf("%c", ptr->n);
		ptr = ptr->prev;
	}
	printf("\n");
}

#include "monty.h"

/**
 * sub - subtracts the first element of the stack from the second element
 *
 * @head: pointer to first element of stack
 * Return: void
 */
void sub(stack_t **head)
{
	stack_t *ptr = *head;
	long subs;

	if (ptr == NULL || ptr->prev == NULL)
		end_process(EXIT_FAILURE, "can't sub, stack too short", *head);
	else
	{
		subs = ptr->n;
		ptr = ptr->prev;
		ptr->next = NULL;
		free(*head);
		*head = ptr;
		ptr->n -= subs;
	}
}

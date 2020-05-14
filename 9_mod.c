#include "monty.h"

/**
 * mod - computes rest of the division of second element of the stack
 * by the top element
 * @head: pointer to first element of stack
 * Return: void
 */
void mod(stack_t **head)
{
	stack_t *ptr = *head;
	long div;

	if (ptr == NULL || ptr->prev == NULL)
		end_process(EXIT_FAILURE, "can't mod, stack too short", *head);
	else
	{
		div = ptr->n;
		if (div == 0)
			end_process(EXIT_FAILURE, "division by zero", *head);
		ptr = ptr->prev;
		ptr->next = NULL;
		free(*head);
		*head = ptr;
		ptr->n %= div;
	}
}

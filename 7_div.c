#include "monty.h"

/**
 * divi - divides the second element of the stack by first element
 *
 * @head: pointer to first element of stack
 * Return: void
 */
void divi(stack_t **head)
{
	stack_t *ptr = *head;
	long div;

	if (ptr == NULL || ptr->prev == NULL)
		end_process(EXIT_FAILURE, "can't div, stack too short", *head);
	else
	{
		div = ptr->n;
		if (div == 0)
			end_process(EXIT_FAILURE, "division by zero", *head);
		ptr = ptr->prev;
		ptr->next = NULL;
		free(*head);
		*head = ptr;
		ptr->n /= div;
	}
}

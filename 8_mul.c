#include "monty.h"

/**
 * mul - multiplies the second element of the stack with the first element
 *
 * @head: pointer to first element of stack
 * Return: void
 */
void mul(stack_t **head)
{
	stack_t *ptr = *head;
	long mult;

	if (ptr == NULL || ptr->prev == NULL)
		end_process(EXIT_FAILURE, "can't mul, stack too short", *head);
	else
	{
		mult = ptr->n;
		ptr = ptr->prev;
		ptr->next = NULL;
		free(*head);
		*head = ptr;
		ptr->n *= mult;
	}
}

#include "monty.h"

/**
 * add - adds the first two elements of the stack.
 *
 * @head: pointer to first position of stack
 * Return: void
 */
void add(stack_t **head)
{
	stack_t *ptr = *head;
	long sum;

	if (ptr == NULL || ptr->prev == NULL)
		end_process(EXIT_FAILURE, "can't add, stack too short", *head);
	else
	{
		sum = ptr->n;
		ptr = ptr->prev;
		ptr->next = NULL;
		free(*head);
		*head = ptr;
		ptr->n += sum;
	}
}

#include "monty.h"

/**
 * pop - removes the top element of the stack
 *
 * @head: head pointer to first position of stack
 * Return: void
 */
void pop(stack_t **head)
{
	stack_t *ptr = *head;

	if (ptr == NULL)
		end_process(EXIT_FAILURE, "can't pop an empty stack", *head);
	if (ptr->prev == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		ptr = ptr->prev;
		ptr->next = NULL;
		free(*head);
		*head = ptr;
	}
}

#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @head: head pointer to first element position of stack
 * @tail: last position element  of stack
 * Return: void
 */
void swap(stack_t **head, stack_t **tail)
{
	stack_t *ptr = *head;

	if (ptr == NULL || ptr->prev == NULL)
		end_process(EXIT_FAILURE, "can't swap, stack too short", *head);
	ptr = ptr->prev;
	(*head)->prev = ptr->prev;
	ptr->next = (*head)->next;
	ptr->prev = *head;
	(*head)->next = ptr;
	*head = ptr;
	if ((*tail)->prev != NULL)
		*tail = (*head)->prev;
}

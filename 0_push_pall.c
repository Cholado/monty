#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @head: first position of stack
 * @tail: last position of stack
 * @val: value to dereference
 * @status: stack or queue status (where to place the waiting instruction)
 * Return: void
 */
void push(stack_t **head, stack_t **tail, int val, int status)
{
	stack_t *ptr;

	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
	{
		printf("Error: malloc failed\n");
		end_process(EXIT_FAILURE, NULL, *head);
	}
	ptr->n = val;
	if (*head == NULL)
	{
		ptr->prev = NULL;
		ptr->next = NULL;
		*head = ptr;
		*tail = ptr;
	}
	else if (status == STACK)
	{
		ptr->next = NULL;
		ptr->prev = *head;
		(*head)->next = ptr;
		*head = ptr;
	}
	else if (status == QUEUE)
	{
		ptr->prev = NULL;
		ptr->next = *tail;
		(*tail)->prev = ptr;
		*tail = ptr;
	}
}

/**
 * pall - prints all values on the stack, start from head of stack
 *
 * @head: head pointer of first position of stack
 * Return: void
 */
void pall(stack_t **head)
{
	stack_t *ptr = *head;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->prev;
	}
}

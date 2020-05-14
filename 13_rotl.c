#include "monty.h"

/**
 * rotl - rotate left the stack, first element of stack goes to last
 * @head: pointer to first element of stack
 * @tail: pointer to last element of stack
 * Description: [123] < [321]
 * Return: void
 */
void rotl(stack_t **head, stack_t **tail)
{
	stack_t *ptrt = *head, *ptrb = *tail;

	if (ptrt == NULL || ptrt->prev == NULL)
		return;
	ptrt->next = ptrb;
	ptrb->prev = ptrt;
	*head = ptrt->prev;
	(*head)->next = NULL;
	*tail = ptrt;
	ptrt->prev = NULL;
}

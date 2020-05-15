#include "monty.h"

/**
 * rotr - rotate right the stack, last element of stack goes to first
 * @head: pointer to first element of stack
 * @tail: pointer to last element  of stack
 * Description: [123] > [321]
 */
void rotr(stack_t **head, stack_t **tail)
{
	stack_t *ptrt = *head, *ptrb = *tail;

	if (ptrt == NULL || ptrt->prev == NULL)
		return;
	ptrt->next = ptrb;
	ptrb->prev = ptrt;
	*tail = ptrb->next;
	(*head)->prev = NULL;
	*head = ptrb;
	ptrb->next = NULL;
}

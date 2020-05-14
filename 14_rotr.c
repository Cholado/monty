#include "monty.h"

/**
 * rotr - rotate right the stack, last element of stack goes to first
 * @head: pointer to first element of stack
 * @tail: pointer to last element  of stack
 * Description: [123] > [321]
 */
void rotr(stack_t **top, stack_t **bot)
{
	stack_t *ptrt = *top, *ptrb = *bot;

	if (ptrt == NULL || ptrt->prev == NULL)
		return;
	ptrt->next = ptrb;
	ptrb->prev = ptrt;
	*bot = ptrb->next;
	(*bot)->prev = NULL;
	*top = ptrb;
	ptrb->next = NULL;
}

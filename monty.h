#ifndef _MONTY_H_
#define _MONTY_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define QUEUE 1
#define STACK 0

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * union f_type - store types regarding types of stack (or queue) management
 * @single: function for one element only
 * @plural: function for multiple elements
 * @tips: function for only the first and last spots
 * Description: allows to store types of function in the same memory location
 */
union f_type
{
	void (*single)(stack_t **head);
	void (*plural)(stack_t **head, stack_t **tail, int value, int mode);
	void (*tips)(stack_t **head, stack_t **tail);
};

/**
 * struct operation_code - match each opcode to the stack management function
 * @opcode: the opcode
 * @func: function to handle the opcode
 *
 * Description: opcode and its function
 */
typedef struct operation_code
{
	char *opcode;
	union f_type func;
} op_t;

/**
 * struct global_v - global variable to handle input
 * @buffer: string manipulation holder
 * @linenum: number of lines
 * @script: file stucture pointer for I/O
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_v
{
	char *buffer;
	unsigned long linenum;
	FILE *script;
} global_v;

/* tools.c */
int isdigits(char *str);

/* lexical analyzer */
int parser(op_t *ins);
op_t *run_instructions(void);
void end_process(int e_num, char *message, stack_t *head);
/* 0_push_pall.c */
void push(stack_t **head, stack_t **tail, int val, int status);
void pall(stack_t **head);
/* 1_pint.c */
void pint(stack_t **head);
/* 2_pop.c */
void pop(stack_t **head);
/* 3_swap.c */
void swap(stack_t **head, stack_t **tail);
/* 4_add.c */
void add(stack_t **head);
/* 6_sub.c */
void sub(stack_t **head);
/* 7_div.c */
void divi(stack_t **head);
/* 8_mul.c */
void mul(stack_t **head);
/* 9_mod.c */
void mod(stack_t **head);
/* 11_pchar.c */
void pchar(stack_t **head);
/* 12_pstr.c */
void pstr(stack_t **head);
/* 13_rotl.c */
void rotl(stack_t **head, stack_t **tail);
/* 14_rotr.c */
void rotr(stack_t **head, stack_t **tail);

#endif /* _MONTY_H_ */

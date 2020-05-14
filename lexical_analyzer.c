#define _GNU_SOURCE
#include "monty.h"
#define I_DONE 14

static global_v gv;

/**
 * end_process - free memory allocation, exit program, print error messages
 * @e_num: exit number to end process
 * @message: error string to print
 * @head: stack head pointer to free
 */
void end_process(int e_num, char *message, stack_t *head)
{
	stack_t *ptr = head;

	if (message != NULL)
		printf("L%lu: %s\n", gv.linenum, message);
	while (head != NULL)
	{
		ptr = head->prev;
		free(head);
		head = ptr;
	}
	free(gv.buffer);
	fclose(gv.script);
	exit(e_num);
}

/**
 * parser - takes input data & builds a data structure from script files
 * @ins: array of instructions and pointers to functions for the opcodes
 *
 * Return: 0 on success
 */
int parser(op_t *ins)
{
	size_t len = 0, val, status = STACK;
	stack_t *head = NULL, *tail = NULL;
	char *token;

	while (getline(&gv.buffer, &len, gv.script) > 0)
	{
		if (gv.buffer == NULL)
		{
			printf("Error: malloc failed\n");
		end_process(EXIT_FAILURE, NULL, head);
		}
		token = strtok(gv.buffer, "\n ");
		if (token != NULL)
		{
			val = 0;
			if (*token == '#' || !strcmp(token, "nop"))
				;
			else if (!strcmp(token, "queue"))
				status = QUEUE;
			else if (!strcmp(token, "stack"))
				status = STACK;
			else
			{
				while (val < I_DONE && strcmp(token, ins[val].opcode))
					val++;
				if (val == 0)
				{
					token = strtok(NULL, "\n ");
					if (token == NULL || !isdigits(token))
						end_process(EXIT_FAILURE, "usage: push integer", head);
					ins[0].func.plural(&head, &tail, atoi(token), status);
				}
				else if (val < 4)
					ins[val].func.tips(&head, &tail);
				else if (val < I_DONE)
					ins[val].func.single(&head);
				else
				{
					printf("L%ld: unknown instruction %s\n", gv.linenum, token);
					end_process(EXIT_FAILURE, NULL, head);
				}
			}
		}
		free(gv.buffer);
		gv.buffer = NULL;
		len = 0;
		gv.linenum++;
	}
	end_process(EXIT_SUCCESS, NULL, head);
	return (0);
}

/**
 * run_instructions - initialize array of operation codes & respective funcs
 *
 * Return: op_t array
 */
op_t *run_instructions(void)
{
	static op_t head[14];

	head[0].opcode = "push";
	head[0].func.plural = push;
	head[1].opcode = "rotl";
	head[1].func.tips = rotl;
	head[2].opcode = "rotr";
	head[2].func.tips = rotr;
	head[3].opcode = "swap";
	head[3].func.tips = swap;
	head[4].opcode = "pop";
	head[4].func.single = pop;
	head[5].opcode = "pall";
	head[5].func.single = pall;
	head[6].opcode = "pint";
	head[6].func.single = pint;
	head[7].opcode = "pchar";
	head[7].func.single = pchar;
	head[8].opcode = "pstr";
	head[8].func.single = pstr;
	head[9].opcode = "add";
	head[9].func.single = add;
	head[10].opcode = "sub";
	head[10].func.single = sub;
	head[11].opcode = "mul";
	head[11].func.single = mul;
	head[12].opcode = "div";
	head[12].func.single = divi;
	head[13].opcode = "mod";
	head[13].func.single = mod;

	return (head);
}

/**
 * main - Lexical analizer checks the monty script file from input
 *
 * @ac: arguments counter
 * @av: arguments values
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE otherwise
 */
int main(int ac, char *av[])
{
	op_t *instructions;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	gv.script = fopen(av[1], "r"); /* read file */
	if (gv.script == NULL)
	{
		printf("Error: Can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}
	instructions = run_instructions();
	gv.linenum = 1;
	parser(instructions);
	return (0);
}

#undef I_DONE

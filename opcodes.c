#include "monty.h"
/**
 * _push - pushes an element to the stack
 * @stack: double pointer
 * @line_number: unsigned int
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = line_number;
	new->next = *stack;
	new->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * _pall - prints all the values on the stack, starting from the top of the stack
 * @stack: double pointer
 * @line_number: unsigned int
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *aux = *stack;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _pint - prints the value at the top of the stack, followed by a new line
 * @stack: double pointer
 * @line_number: unsigned int
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stedrr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("d\n", (*stack)->n);
}

/**
 * _pop - removes the top element of the stack
 * @stack: double pointer
 * @line_number: unsigned int
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (*stack)
			*stack = (*stack)->next; /*moves to next element*/
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	free(temp);
}

/**
 * _nop - doesn’t do anything
 * @stack: double pointer
 * @line_number: unsigned int
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

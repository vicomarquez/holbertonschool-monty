#include "main.h"
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
	stack_t aux = *stack;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
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

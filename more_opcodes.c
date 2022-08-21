#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 * @stack: double pointer
 * @line_number: unsigned int
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int n;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_list(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = n;
}

/**
 * _add - adds the top two elements of the stack
 * @stack: double pointer
 * @line_number: unsigned int
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_list(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	stack_temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n += stack_temp->n;
	(*stack)->prev = NULL;
	free(stack_temp);
}

/**
 * free_list - frees a listi
 *
 * @head: pointer to head
 *
 * Return: the address of the new element, or NULL if it failed
 */
void free_list(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}


#include "monty.h"
/**
 * main - monty interpreter
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	FILE *txt;
	char *line = NULL, *head = NULL;
	char buffer[1024];
	stack_t *stack = NULL;
	unsigned int numb_line = 0;
	void (*f)(stack_t **, unsigned int);

	if (argc != 2)
	{
		dprintf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	txt = fopen(argv[1], "r");
	if (!txt)
	{
		dprintf("Error: Can't open file txt\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, 1024, txt) == -1)
	{
		numb_line++;
		line = strtok(buffer, "\n");
		if (!Line)
			continue;
		head = strtok(line, "\t\r");
		if (head)
		{
			f = get_op(head, numb_line);
			if (f)
					f(&stack, numb_line);
		}

	}
	free_dlistint(stack);
	fclose(fp);
return (0);
}

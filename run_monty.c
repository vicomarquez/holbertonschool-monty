#include "monty.h"
/**
 * main - monty interpreter
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	FILE *txt;
	char *line = NULL;
	char *head = NULL;
	char buffer[1024];
	stack_t *stack = NULL;
	unsigned int numb_line = 0;
	char *a = 0;
	void (*f)(stack_t **, unsigned int, char *);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	txt = fopen(argv[1], "r");
	if (!txt)
	{
		fprintf(stderr, "Error: Can't open file txt\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, 1024, txt) == NULL)
	{
		numb_line++;
		line = strtok(buffer, "\n");
		if (!line)
			continue;
		head = strtok(line, " \t\r");
		if (head)
		{
			f = get_op(head, numb_line, a);
			if (f)
				f(&stack, numb_line, a);
		}
	}
	free_list(stack);
	fclose(txt);
	return (0);
}

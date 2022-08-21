#include "monty.h"
/**
 * main - monty interpreter
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	FILE *txt;
	/*char *line = 0, *head = 0;
	int buff = 0, i = 0;*/

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
	/*while (getline(&line,&buff,txt)== -1)
	{
			
	}*/	
}

#include "RSA.h"

/**
 * main - start point of program
 * @argc: number of arguments
 * @argv: pointer of arguments
 *
 * Return: 0 if succeded, 98 if errer occured
 */
int main(int argc, char *argv[])
{
	FILE *f;
	char *lineptr;
	size_t size;
	ssize_t line_num;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factor <filename>\n");
		exit(EXIT_FAILURE);
	}

	f = fopen(argv[1], "r");

	if (f == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((line_num = getline(&lineptr, &size, f)) != -1)
	{
		fc(lineptr);
	}
	return (0);

}

/**
 * fc - func that factorize the number 
 * @number: number to be factorized
 * Return: 0 always
 */
int fc(char *number)
{
	u_int32_t n, m;

	n = atoll(number);
	for (m = 2; m < n; m++)
	{
		if (n % m == 0)
		{
			printf("%d=%d*%d\n", n, n/m, m);
			break;
		}
	}
return (0);
}

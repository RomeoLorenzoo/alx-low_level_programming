#include <stdio.h>
#include <stdlib.h>

/**
 * _isdigit - checks if a character is a digit
 *
 * @c: character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * print_error - prints an error message and exits with status 98
 */
void print_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * multiply - multiplies two numbers represented as strings
 *
 * @num1: first number
 * @num2: second number
 *
 * Return: a pointer to the result, represented as a string
 */
char *multiply(char *num1, char *num2)
{
	int len1, len2, i, j, k, carry, sum;
	char *result;

	len1 = 0;
	while (num1[len1])
	{
		if (!_isdigit(num1[len1]))
			print_error();
		len1++;
	}

	len2 = 0;
	while (num2[len2])
	{
		if (!_isdigit(num2[len2]))
			print_error();
		len2++;
	}

	result = calloc(len1 + len2, sizeof(*result));
	if (result == NULL)
		exit(98);

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			k = i + j + 1;
			sum = (num1[i] - '0') * (num2[j] - '0') + carry + result[k];
			result[k] = sum % 10;
			carry = sum / 10;
		}
		result[i] += carry;
	}

	i = 0;
	while (i < len1 + len2 && result[i] == 0)
		i++;

	if (i == len1 + len2)
	{
		free(result);
		return ("0");
	}

	for (j = 0; j < len1 + len2; j++)
		result[j] += '0';

	return (result + i);
}

/**
 * main - multiplies two positive numbers
 *
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	char *num1, *num2, *result;

	if (argc != 3)
	{
		print_error();
	}

	num1 = argv[1];
	num2 = argv[2];

	result = multiply(num1, num2);

	printf("%s\n", result);

	free(result);

	return (0);
}


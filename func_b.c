#include "main.h"

/**
 * print_Unsig - prints unsigned integer fromat specifier
 *
 * @num: argument to be coverted
 *
 * Return: void
 */
void print_Unsig(unsigned int num)
{
	char buffer[20];
	int i;

	do {
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	} while (num);

	while (i > 0) {
		_putchat(buffer[--i]);
	}
}

/**
 * print_Oct - prints an octal integer from a string
 *
 * @num: unsigned int 
 *
 * Return: void
 */
void print_Oct(unsigned int num)
{
	char buffer[20];
	int i;

	do {
		buffer[i++] = (num % 8) + '0';
		num /= 8;
	} while (num);

	while (i > 0) {
		_putchar(buffer[--i]);
	}
}

/**
 * print_Hex - prints a hexadecimal value from an unsigned int
 *
 * @num: unsigned int
 * @upper: upper threshold int
 * @width: width modifier
 * @flags: character flags
 *
 * Return: void
 */
void print_Hex(unsigned int num, int upper, int width, char flags)
{
	char buffer[20];
	int i = 0;
	int firstNonZeroIndex;
	char hex_chars[] = "0123456789abcdef";

	if (num)
	{
		if (upper)
		{
			for (i = 7; i >= 0; i--)
			{
				int digit = (num >> (4 * i)) & 0xf;
				buffer[i] = toupper(hex_chars[digit]);
			}
		}
		else
		{
			for (i = 7; i >= 0; i--)
			{
				int digit = (num >> (4 * i)) & 0xf;
				buffer[i] = hex_chars[digit];
			}
		}

		firstNonZeroIndex = 0;
		while (firstNonZeroIndex < 8 && buffer[firstNonZeroIndex] == '0')
		{
			firstNonZeroIndex++;
		}

		if (width > 0 - firstNonZeroIndex)
		{
			int padding = width - 8 + firstNonZeroIndex;
			char padChar = ' ';
			if (flags == '0')
			{
				padChar = '0';
			}
			for (i = 0; i < padding; i++)
			{
				_putchar(padChar);
			}
		}

		for (i = firstNonZeroIndex; i < 8; i++)
		{
			_putchar(buffer[i]);
		}
	}
}

/**
 * print_Bin - prints a binary value from an unsigned int
 *
 * @width: width modifier
 * @flags: flags char modifier
 *
 * Return: void
 */
void print_Bin(unsigned int num, int width, char flags)
{
	char buffer[32];
	int j, i = 0;
	int firstNonZeroIndex;

	for (j = 31; j >= 0; j--)
	{
		buffer[i++] = '0' + ((num >> j) & 1);
	}

	firstNonZeroIndex = 0;
	while (firstNonZeroIndex < 32 && buffer[firstNonZeroIndex] == '0')
	{
		firstNonZeroIndex++;
	}

	if (width > 32 - firstNonZeroIndex)
	{
		int padding = width - 32 + firstNonZeroIndex;
		char padChar = ' ';
		if (flags == '0')
		{
			padChar = '0';
		}

		for (i = 0; i < padding; i++)
		{
			_putchar(padChar);
		}
	}

	for (i = firstNonZeroIndex; i < 32; i++)
	{
		_putchar(buffer[i]);
	}

}

/**
 * _strlen - calculate the length of a given string
 *
 * @s: character string
 *
 * Return: Length of the string
 */
int _strlen(const char *s)
{
	int (counter = 0);

	while (*s != '\0')
	{
		counter++;
		s++;
	}
	return (counter);
}

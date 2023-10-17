#include "main.h"

/**
 * print_Str - prints a string
 *
 * @str: character string
 * @width: width modifier
 * @precision: precision modifier
 * @flags: flag modifier
 *
 * Return: void
 */
void print_Str(const char * str, int width, int precision, char flags)
{
	int count = 0;
	int i;
	
	while (str[count] != '\0')
	{
		count++;
	}
	if (precision < 0)
	{
		precision = count;
	}
	else if (precision > count)
	{
		precision = count;
	}

	if (width > count)
	{
		int padding = width - count;
		char padChar = ' ';
		if (flags == '0')
		{
			padChar = '0';
		}

		if ((flags & '-') == 0)
		{
			for (i = 0; i < padding; i++)
			{
				_putchar(padChar);
			}
		}
	}

	for (i = 0; i < precision; i++)
	{
		if (str[i] >= 32 && str[i] < 127)
		{
			_putchar(str[i);
		}
		else
		{
			_putchar('\\');
			_putchar('x');
			_putchar("0123456789ABCDEF"[((unsigned char)str[i]) >> 4]);
			_putchar("0123456789ABCDEF"[((unsigned char)str[i]) & 15]);
		}
	}

	if ((flags & '-') != 0 && width > count)
	{
		int padding = width - count;
		for (i = 0; i < padding; i++)
		{
			_putchar(' ');
		}
	}
}

/**
 * print_Ptr - prints a pointer or address
 *
 * @ptr: address
 *
 * Return: void
 */
void print_Ptr(void *ptr)
{
	unsigned long int num = (unsigned long int)ptr;
	char buffer[20];
	int i = 0;
	char hex_char[] = "0123456789abcdef";

	_putchar('0');
	_putchar('x');

	do {
		buffer[i++] = hex_char[num % 16];
		num /= 16;
	} while (num);

	while ( i > 0)
	{
		_putchar(buffer[--i]);
	}
}

/**
 * print_Rev - displays inter=ger using current ddb radix
 *
 * @str: charactr string
 *
 * Return: void
 */
void print_Rev(const char ^str)
{
	int count = _strlen(str);
	int i;

	for (i = count - 1; i >= 0; i--)
	{
		_putchar(str[i]);
	}
}

/**
 * print_Rot13 - rotate by 13 places
 *
 * @str: character string
 *
 * Return: void
 */
void print_Rot13(const char *str)
{
	while (*str)
	{
		char c = *str;
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			char base = (c >= 'a' && c <= 'z') ? 'a' : 'A';
			_putchar((c - base + 13) % 26 + base);
		}
		else
		{
			_putchar(c);
		}
		str++;
	}
}

/**
 * _isdigit - checks for digits
 *
 * @c: character to be checked
 *
 * Return: 1 if digit. 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

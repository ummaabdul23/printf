#include "main.h"
/**
  * print_Char - print characters
  * @c: --
  */
void print_Char(char c)
{
	  _putchar(c);
}
/**
  * print_str - print strings
  * @str: --
  * @width: --
  * @precision: --
  * @flags: --
  * Return: void
  */
void print_str(const char *str, int width, int precision, char flags)
{
	int i;
	int count = 0;

	while (str[count] != '\0')
	{
		count++;
	}
	if (precision < 0)
		precision = count;
	else if (precision > count)
		precision = count;
	if (width > count)
	{
		int padding = width - count;
		char padChar = ' ';

		if (flags == '0')
			padChar = '0';
		if ((flags & '-') == 0)
		{
			for (i = 0; i < padding; i++)
				_putchar(padChar);
		}
	}
	for (i = 0; i < precision; i++)
	{
		_putchar(str[i]);
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
  * print_Dec - print decimals and integers
  * @num: parameter
  * Return: void
  */
void print_Dec(int num)
{
	char buffer[20];
	int i = 0;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}
	do {
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	} while (num);
		while (i > 0)
		{
			_putchar(buffer[--i]);
		}
}
/**
  * print_mod - print modulos
  * Return: void
  */
void print_mod(void)
{
	_putchar('%');
}
/**
  * _putchar - writes the character c to stdout
  * @c: The character to print
  *
  * Return: On success 1.
  * On error, -1 is returned, and errno is set appropriately.
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

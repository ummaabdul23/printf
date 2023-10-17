#include "main.h"
/**
  * _printf - works like the C programming printf
  * @format: --
  */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	int width, precision;
	char flags;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			width = 0;
			precision = -1;
			flags = 0;

		while (*format == '0' || *format == '-')
			flags |= (*format == '0') ? '0' : '-';
			format++;
		while (_isdigit(*format))
			width = width * 10 + (*format - '0');
			format++;
		if (*format == '.')
		{
			format++;
			precision = 0;
			while (_isdigit(*format))
				precision = precision * 10 + (*format - '0');
				format++;
		}
		if (*format == 'c')
			char  c = va_arg(args, int);
			print_Char(c);
		else if (*format == 's')
			const char *str = va_arg(args, const char*);
			print_str(str, width, precision, flags);
		else if (*format == 'd' || *format == 'i')
			int num = va_arg(args, int);
			print_Dec(num);
		else if (*format == 'u')
			unsigned int num = va_arg(args, unsigned int);
			print_Unsig(num);
		else if (*format == 'o')
			unsigned int num = va_arg(args, unsigned int);
			print_Oct(num);
		else if (*format == 'x')
			unsigned int num = va_arg(args, unsigned int);
			print_Hex(num, 0, width, flags);
		else if (*format == 'X')
			unsigned int num = va_arg(args, unsigned int);
			print_Hex(num, 1, width, flags);
		else if (*format == 'b')
			unsigned int num = va_arg(args, unsigned int);
			print_Bin(num, width, flags);
		else if (*format == 'S')
			const char *str = va_arg(args, const char*);
			print_Str(str, width, precision, flags);
		else if (*format == 'p')
		{
			void *ptr = va_arg(args, void*);
			uintptr_t uintptr_ptr = (uintptr_t)ptr;
			_putchar('0');
			_putchar('x');
			print_Hex(uintptr_ptr, 0, 0, 0);
			print_Ptr(ptr);
		}
		else if (*format == 'r')
			const char *str = va_arg(args, const char*);
			print_Rev(str);
		else if (*format == 'R')
			const char *str = va_arg(args, const char*);
			print_Rot13(str);
		else if (*format == '%')
			_putchar('%');
		}
		else
			_putchar(*format);
		format++;
		}
		va_end(args);
}
	return printed_chars;
}

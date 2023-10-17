#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
#include <ctype.h>
#include <stdint.h>

/**
 * struct format - a struct defining a format
 *
 * @id: A pointer to ID
 * @f: function pointer
 *
 */
typedef struct format
{
        char *id;
        int (*f)();
} convert_match;

int _putchar(char c);
void print_mod(void);
void print_Char(char c);
void print_str(const char *str, int width, int precision, char flags);
void print_Dec(int num);
void print_Bin(unsigned int num, int width, char flags);
void print_Hex(unsigned int num, int upper, int width, char flags);
void print_Oct(unsigned int num);
void print_Unsig(unsigned int num);
void print_Str(const char *str, int width, int precision, char flags);
void print_Ptr(void *ptr);
void print_Rev(const char *str);
void print_Rot13(const char *str);
int _strlen(const char *s);
int _printf(const char *format, ...);
int _isdigit(int c);

#endif


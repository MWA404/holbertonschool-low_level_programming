#include "variadic_functions.h"

/**
 * print_char - prints a char
 * @args: va_list with the char
 */
static void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - prints an int
 * @args: va_list with the int
 */
static void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - prints a float
 * @args: va_list with the float
 */
static void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - prints a string
 * @args: va_list with the string
 */
static void print_string(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	if (!str)
	{
		printf("(nil)");
		return;
	}
	printf("%s", str);
}

/**
 * print_all - prints anything
 * @format: list of types of arguments
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i, j;
	char *sep;
	char types[] = "cifs";
	void (*funcs[])(va_list) = {print_char, print_int, print_float,
		print_string};

	va_start(args, format);
	i = 0;
	sep = "";

	while (format && format[i])
	{
		j = 0;
		while (types[j])
		{
			if (format[i] == types[j])
			{
				printf("%s", sep);
				funcs[j](args);
				sep = ", ";
			}
			j++;
		}
		i++;
	}

	printf("\n");
	va_end(args);
}

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"
#include <unistd.h>

int main()
{
	ft_printf("%p\n", 0);
	printf("%p\n", 0);
	return (0);
}

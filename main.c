#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"
#include <unistd.h>

int main()
{
	int n = 2;
	int m;
	int o;

   	m = printf("%03.2d\n", n);
	o = ft_printf("%p\n", &n);
	return (0);
}

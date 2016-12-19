#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"
#include <unistd.h>

int main()
{
	int n = 2;
	ft_printf("%.2p\n", &n);
	printf("%.20p\n", &n);
	return (0);
}

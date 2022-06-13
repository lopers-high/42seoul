#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main()
{
    // int len = printf("%.2147483648d\n", 1);
    // printf("%d\n", len);
    // int k = 0;
    // int len = printf("%.2147483648s\n", "aaa");
    // printf("%d\n", len);
    // len = printf("%.2147483647d\n", 1);
    // printf("%d\n", len);
    // ft_printf("unsigned long long %d\n", 9223372036854775807);
    // ft_printf("unsigned int %d\n", 4294967300);
    int a;
    a = ft_printf("abcdefghij%2147483640d\n", 1);
    printf("a : %d", a);
}
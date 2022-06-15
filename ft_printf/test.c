#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main()
{
    // int len = printf("%.2147483648d\n", 1);
    // printf("%d\n", len);
    int *k;
    // int len = printf("%.2147483648s\n", "aaa");
    // printf("%d\n", len);
    // len = printf("%.2147483647d\n", 1);
    // printf("%d\n", len);
    // ft_printf("unsigned long long %d\n", ç);
    // ft_printf("unsigned int %d\n", 4294967300);
    //9223372036854775807
    // 9223372039002259454
    // 9223372041149743101
    int a;
    a = printf("%9223372039002259500d\n", 1);
    printf("a : %d", a);
}

// ~INT_MAX 잘나옴
// INT_MAX ~ LLONG MAX -1
// LLONG_MAX+1  ~ INT_MAX 잘나옴
// INT_MAX ~~  플래그안먹힘 추렭은 잘됨
// INT_MAX * 2


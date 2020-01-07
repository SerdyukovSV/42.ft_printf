#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

#define PREFIX "0x"
/* #define H  (16)
#define HH (32)
#define L  (64)
#define LL (128) */


int main(void)
{   

    char *str = "adress pointer";
    char *str2 = "adress variable";
    char *str3 = "Nice day";
    char c = ':';
    
    int a = 5;
    int *p = &a;
    // intptr_t nb = sizeof(intptr_t);
    // ft_printf("%-15.7s %% %c %-20p %% W%.s %c %p\n", str, c, &p, str2, c, p);
    //    printf("%-15.7s %% %c %-20p %% W%.s %c %p\n", str, c, &p, str2, c, p);

    struct  test
    {
        int flag;
    }       t_test;
    
    int d = 0x7fffffff;
    short int aa = sizeof(intmax_t);
    wchar_t ch = L'ф';
    
    // int c = 1 << 3;
    int f = 1 << 5;

    t_test.flag |= HH;
    // t_test.flag |= f;
    int i = (t_test.flag & HH) ? 2 : 1;

    unsigned long nb1 = 564;
    unsigned long long nb2 = UINT64_MAX;
    double ff = 57.8956;
    i = ff / 10;
    printf("%d\n", i);
    // printf("%d %d\n", t_test.flag & c, t_test.flag & f);
    // printf("a = %i, b = %i, c = %i\n", 12, 012, 0x12);
    // printf("a = %d, b = %d, c = %d\n", 12, 012, 0x12);
    // printf("ο Δικαιοπολις εν αγρω εστιν\n");
    // ft_printf("ο Δικαιοπολις εν αγρω εστιν\n");
    return 0;
}
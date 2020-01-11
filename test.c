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
    double ff = 57.00000;
    i = -123;

    // printf("asd%cfghj\n", c2);
    // printf("%+07d %d\n", i, i);
    
    // printf("%+8.5d %d\n", i, i); //НЕ РАБОТАЕТ. При выводе 0 учитывается только 1 параметр (флаг '0' && '.') если указан '.' то флаг '0' не учитывается
    // printf("% 8.5d %d\n", i, i);


        /* printf("1\n");
              printf("%+d\n", i);
           ft_printf("%+d\n", i);
        printf("2\n");
              printf("% d\n", i);
           ft_printf("% d\n", i);
        printf("3\n");
              printf("%+7d\n", i);
           ft_printf("%+7d\n", i);
        printf("4\n");
              printf("% 7d\n", i);
           ft_printf("% 7d\n", i);
        printf("5\n");
              printf("%+07d\n", i);
           ft_printf("%+07d\n", i);
        printf("6\n");
              printf("% 07d\n", i);
           ft_printf("% 07d\n", i);
        printf("7\n");
              printf("%+07.5d\n", i);
           ft_printf("%+07.5d\n", i);
        printf("8\n");
              printf("% 07.5d\n", i);
           ft_printf("% 07.5d\n", i);
        printf("9\n");        
              printf("%+7.5d\n", i);
           ft_printf("%+7.5d\n", i);
        printf("10\n");        
              printf("% 7.5d\n", i);
           ft_printf("% 7.5d\n", i);
        printf("11\n");        
              printf("%+0.5d\n", i);
           ft_printf("%+0.5d\n", i);
        printf("12\n");        
              printf("% 0.5d\n", i);
           ft_printf("% 0.5d\n", i);
        printf("13\n");        
              printf("%+.5d\n", i);
           ft_printf("%+.5d\n", i);
        printf("14\n");        
              printf("% .5d\n", i);
           ft_printf("% .5d\n", i);
        printf("15\n");        
              printf("%.d\n", i);
           ft_printf("%.d\n", i);

        printf("1\n");
              printf("%+-d %d\n", i, i);
           ft_printf("%+-d %d\n", i, i);
        printf("2\n");
              printf("% -d %d\n", i, i);
           ft_printf("% -d %d\n", i, i);
        printf("3\n");
              printf("%+-7d %d\n", i, i);
           ft_printf("%+-7d %d\n", i, i);
        printf("4\n");
              printf("% -7d %d\n", i, i);
           ft_printf("% -7d %d\n", i, i);
        printf("5\n");
              printf("%+-07d %d\n", i, i);
           ft_printf("%+-07d %d\n", i, i);
        printf("6\n");
              printf("% -07d %d\n", i, i);
           ft_printf("% -07d %d\n", i, i);
        printf("7\n");
              printf("%+-07.5d %d\n", i, i);
           ft_printf("%+-07.5d %d\n", i, i);
        printf("8\n");
              printf("% -07.5d %d\n", i, i);
           ft_printf("% -07.5d %d\n", i, i);
        printf("9\n");        
              printf("%+-7.5d %d\n", i, i);
           ft_printf("%+-7.5d %d\n", i, i);
        printf("10\n");        
              printf("% -7.5d %d\n", i, i);
           ft_printf("% -7.5d %d\n", i, i);
        printf("11\n");        
              printf("%+-0.5d %d\n", i, i);
           ft_printf("%+-0.5d %d\n", i, i);
        printf("12\n");        
              printf("% -0.5d %d\n", i, i);
           ft_printf("% -0.5d %d\n", i, i);
        printf("13\n");        
              printf("%+-.5d %d\n", i, i);
           ft_printf("%+-.5d %d\n", i, i);
        printf("14\n");        
              printf("% -.5d %d\n", i, i);
           ft_printf("% -.5d %d\n", i, i);
        printf("15\n");        
              printf("%-.d %d\n", i, i);
           ft_printf("%-.d %d\n", i, i); */

    // int q = UINT64_MAX;
       printf("%lu\n", UINT64_MAX);
    ft_printf("%llu\n", UINT64_MAX);


    /*                flsgs          
    priority |   | - | + |' '| # | 0 | WIDTH |
        d    | - | 0 | 1 | 1 | ? | 0 |   1   |
             | + | 1 | 0 | 0 | ? | 1 |   1   |
             |' '| 1 | 0 | 0 | ? | 1 |'-' '0'|
             | # | ? | ? | ? | ? | ? |   ?   |
             | 0 | 0 | 1 | 1 | ? | 0 |   ?   |
    */    

    // width 
    return 0;
}
/* 
void    print_flags(char ch1, int n1, char ch2, int n2, char ch3, int n3)
{
    while (ch1 && n1 > 0)
        ft_putchar(ch1);
    while (ch2 && n2 > 0)
        ft_putchar(ch2);
    while (ch3 && n3 > 0)
        ft_putchar(ch3);
} */
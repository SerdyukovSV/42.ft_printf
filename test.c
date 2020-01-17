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

   //  char *str = "adress pointer";
   //  char *str2 = "adress variable";
   //  char *str3 = "Nice day";
   //  char c = ':';
    
   //  int a = 5;
   //  int *p = &a;
    // intptr_t nb = sizeof(intptr_t);
    // ft_printf("%-15.7s %% %c %-20p %% W%.s %c %p\n", str, c, &p, str2, c, p);
    //    printf("%-15.7s %% %c %-20p %% W%.s %c %p\n", str, c, &p, str2, c, p);

   //  struct  test
   //  {
   //      int flag;
   //  }       t_test;
    
   // //  int d = 0x7fffffff;
   //  short int aa = sizeof(intmax_t);
   //  wchar_t ch = L'ф';
    
   //  // int c = 1 << 3;
   // //  int f = 1 << 5;

   //  t_test.flag |= HH;
   //  // t_test.flag |= f;
   //  int i;

   //  unsigned long nb1 = 564;
   //  unsigned long long nb2 = UINT64_MAX;
   //  double ff = 57.00000;

   long double f = 3.332999999999999740651901447563432157039642333984375;
   long double d2 = 0.420000;
   double d = 0.000000000000000222044604925031308084726333618164062;
   //            0000000000000002220446049250313080847263336181640625
   long double d3 = 2.220446049250313081e-16 /*  */;
   unsigned long l = (unsigned long)d3;
   unsigned char ch;
   int i =0;
   ch = (unsigned char)d2;
   // printf("%u\n", ch);
   while (d2)
   {
      d2 *= 10;
      ch = (unsigned char)d2;
      d2 -= (long double)ch;
      i += 1;
      // printf("%u", ch);
   }
   // printf("\n%Lf\n", f);
   printf("i = %d\n", i);
   char *str = "6664999999999998703259507237817160785198211669921875";
   printf("strlen(str) = %zd\n", ft_strlen(str));
   //    if (d3 < 1)
   
   //0.0078125

   //  0.5 + 0.175 + 0.03125 + 0.007 812 5 + 0.001 953 125
   //             0.10725
   //             0.1
   //             0.20725

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
        printf("16\n");
              printf("%7d\n", i);
           ft_printf("%7d\n", i); */

      /*  printf("1\n");
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
      //  printf("% u\n", i); -
      // printf("%+u\n", i); -
      // unsigned long w = UINT32_MAX;
      // intptr_t p = UINT64_MAX;
      
         // printf("%07x %#X\n", i, i);
         // printf("%#10.15x\n", INT16_MAX);
         // printf("%#07x\n", INT16_MAX);
      //    printf("%#09.15X\t%#09.15x\t%X\t%x\n", INT16_MAX, INT16_MAX, INT16_MAX, INT16_MAX);
      // ft_printf("%#09.15X\t%#09.15x\t%X\t%x\n", INT16_MAX, INT16_MAX, INT16_MAX, INT16_MAX);
      //    printf("%X\n", INT16_MAX);
      //    printf("%#-10X\t%#x\t%#-15.10X\n", INT16_MAX, INT16_MAX, INT16_MAX);
      // ft_printf("%#-10X\t%#x\t%#-15.10X\n", INT16_MAX, INT16_MAX, INT16_MAX);
      //    printf("%#15X\t%.10X\n", INT16_MAX, INT16_MAX);
      // ft_printf("%#15X\t%.10X\n", INT16_MAX, INT16_MAX);

      //      printf("%o\n", INT16_MAX);
      //   ft_printf("%o\n", INT16_MAX);
      //    printf("\n%#o\n", INT16_MAX);
      //   ft_printf("%#o\n", INT16_MAX);
      //    printf("\n%9o\n", INT16_MAX);
      //   ft_printf("%9o\n", INT16_MAX);
      //    printf("\n%09o\n", INT16_MAX);
      //   ft_printf("%09o\n", INT16_MAX);
      //    printf("\n%#9o\n", INT16_MAX);
      //   ft_printf("%#9o\n", INT16_MAX);
      //    printf("\n%#09o\n", INT16_MAX);
      //   ft_printf("%#09o\n", INT16_MAX);
      //    printf("\n%#.9o\n", INT16_MAX);
      //   ft_printf("%#.9o\n", INT16_MAX);      
      //    printf("\n%15.9o\n", INT16_MAX);
      //   ft_printf("%15.9o\n", INT16_MAX);
      //    printf("\n%#15.9o\n", INT16_MAX);
      //   ft_printf("%#15.9o\n", INT16_MAX);
        
      //   printf("-------------------------\n");
      //      printf("%-o\t%o\n", INT16_MAX, INT16_MAX);
      //   ft_printf("%-o\t%o\n", INT16_MAX, INT16_MAX);
      //    printf("\n%#-o\t%#o\n", INT16_MAX, INT16_MAX);
      //   ft_printf("%#-o\t%#o\n", INT16_MAX, INT16_MAX);
      //    printf("\n%-9o\t%9o\n", INT16_MAX, INT16_MAX);
      //   ft_printf("%-9o\t%9o\n", INT16_MAX, INT16_MAX);
      //    printf("\n%-9o\t%09o\n", INT16_MAX, INT16_MAX);
      //   ft_printf("%-9o\t%09o\n", INT16_MAX, INT16_MAX);
      //    printf("\n%#-9o\t%#9o\n", INT16_MAX, INT16_MAX);
      //   ft_printf("%#-9o\t%#9o\n", INT16_MAX, INT16_MAX);
      //    printf("\n%#-9o\t%#09o\n", INT16_MAX, INT16_MAX);
      //   ft_printf("%#-9o\t%#09o\n", INT16_MAX, INT16_MAX);
      //    printf("\n%#-.9o\t%#.9o\n", INT16_MAX, INT16_MAX);
      //   ft_printf("%#-.9o\t%#.9o\n", INT16_MAX, INT16_MAX);
      //    printf("\n%-15.9o\t%15.9o\n", INT16_MAX, INT16_MAX);
      //   ft_printf("%-15.9o\t%15.9o\n", INT16_MAX, INT16_MAX);
      //    printf("\n%#-15.9o\t%#15.9o\n", INT16_MAX, INT16_MAX);
      //   ft_printf("%#-15.9o\t%#15.9o\n", INT16_MAX, INT16_MAX);

      // printf("%o\n", w);

         /* printf("%7u %u\n", i, i);
      ft_printf("%7u %u\n", i, i);
         printf("%-7u %u\n", i, i);
      ft_printf("%-7u %u\n", i, i);
         printf("%07u %u\n", i, i);
      ft_printf("%07u %u\n", i, i);
         printf("%.5u %u\n", i, i);
      ft_printf("%.5u %u\n", i, i);
         printf("%7.5u %u\n", i, i);
      ft_printf("%7.5u %u\n", i, i);
         printf("%-7.5u %u\n", i, i);
      ft_printf("%-7.5u %u\n", i, i); */
         
   //  ft_printf("%llu\n", UINT64_MAX);


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
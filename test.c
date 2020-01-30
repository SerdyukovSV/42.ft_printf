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
    
    int aa = 5;
    int *p = &aa;
    intptr_t nb = sizeof(intptr_t);
   //  ft_printf("%-15.7s %% %c %-20p %% W%.s %c %p\n", str, c, &p, str2, c, p);
   //     printf("%-15.7s %% %c %-20p %% W%.s %c %p\n", str, c, &p, str2, c, p);
   //    printf("\n\n");

   


   int i = -755;
   int i2 = 755;
   float a = 0.42;
   float a2 = -0.42;
   float f = __FLT_MAX__;
   float f2 = __FLT_MIN__;
   double d = __DBL_MAX__;
   double d2 = __DBL_MIN__;
   long double dl = __LDBL_MAX__;
   long double dl2 = __LDBL_MIN__;

   int len;
   int len2;

   // len = ft_printf("% 5f\n", a);
   //    len2 = printf("% 5f\n", a);
   // len += ft_printf("% 020.9f\n", a);
   //    len2 += printf("% 020.9f\n", a);
   //  len += ft_printf("%% % .9f\n% 020.9f\n%d %%\n", a2, a, i);
   //    len2 += printf("%% % .9f\n% 020.9f\n%d %%\n", a2, a, i);
   // len += ft_printf("% -20.9f\n% 20.9f\n%d\n", a2, a, i);
   //    len2 += printf("% -20.9f\n% 20.9f\n%d\n", a2, a, i);
   // len += ft_printf("% 20.9f\n", a);
   //    len2 += printf("% 20.9f\n", a);
   // len += ft_printf("% -20.9f\n%+20.9f\n%d\n", a2, a, i);
   //    len2 += printf("% -20.9f\n%+20.9f\n%d\n", a2, a, i);
   // len += ft_printf("% -200.10f %.100f %+20.10f\n", f, f2, a);
   //    len2 += printf("% -200.10f %.100f %+20.10f\n", f, f2, a);
   // printf("len %d | len2 %d\n", len, len2);

   // len += ft_printf("%f\n", d);
   //    len2 += printf("%f\n", d);
   // ft_printf("%Lf\n", dl);
      // printf("%Lf\n", dl);
   // len += ft_printf("%.120f\n", f2);
   //    len2 += printf("%.120f\n", f2);
   // len += ft_printf("%.500f\n", d2);
   //    len2 += printf("%.500f\n", d2);
   // ft_printf("%.1000Lf\n", dl2);
   //    printf("%.1000Lf\n", dl2);
   // printf("len %d | len2 %d\n", len, len2);

   
//----------------------------------------------------------------

    // printf("asd%cfghj\n", c2);
    // printf("%+07d %d\n", i, i);
      i = __INT_MAX__;
      i2 = INT32_MIN;        

         //   ft_printf("\n%+d\n%d\n", i, i2);

      //    printf("\n");
      //         printf("%d\n", printf("%+d\n", i));
      //      printf("%d\n", ft_printf("%+d\n", i));
      //   printf("2\n");
      //         printf("%d\n", printf("% d\n", i));
      //      printf("%d\n", ft_printf("% d\n", i));
      //   printf("\n");
      //         printf("%d\n", printf("%+7d\n", i));
      //      printf("%d\n", ft_printf("%+7d\n", i));
      //   printf("\n");
      //         printf("%d\n", printf("% 7d\n", i));
      //      printf("%d\n", ft_printf("% 7d\n", i));
      //   printf("\n");
      //         printf("%d\n", printf("%+07d\n", i));
      //      printf("%d\n", ft_printf("%+07d\n", i));
      //   printf("\n");
      //         printf("%d\n", printf("% 07d\n", i));
      //      printf("%d\n", ft_printf("% 07d\n", i));
      //   printf("\n");
      //         printf("%d\n", printf("%+07.5d\n", i));
      //      printf("%d\n", ft_printf("%+07.5d\n", i));
      //   printf("\n");
      //         printf("%d\n", printf("% 07.5d\n", i));
      //      printf("%d\n", ft_printf("% 07.5d\n", i));
      //   printf("\n");     
      //         printf("%d\n", printf("%+7.5d\n", i));
      //      printf("%d\n", ft_printf("%+7.5d\n", i));
      //   printf("\n");      
      //         printf("%d\n", printf("% 7.5d\n", i));
      //      printf("%d\n", ft_printf("% 7.5d\n", i));
      //   printf("\n");        
      //         printf("%d\n", printf("%+0.5d\n", i));
      //      printf("%d\n", ft_printf("%+0.5d\n", i));
      //   printf("\n");        
      //         printf("%d\n", printf("% 0.5d\n", i));
      //      printf("%d\n", ft_printf("% 0.5d\n", i));
      //   printf("\n");        
      //         printf("%d\n", printf("%+.5d\n", i));
      //      printf("%d\n", ft_printf("%+.5d\n", i));
      //   printf("\n");        
      //         printf("%d\n", printf("% .5d\n", i));
      //      printf("%d\n", ft_printf("% .5d\n", i));
      //   printf("\n");        
      //         printf("%d\n", printf("%.d\n", i));
      //      printf("%d\n", ft_printf("%.d\n", i));
      //   printf("\n");
      //         printf("%d\n", printf("%7d\n", i));
      //      printf("%d\n", ft_printf("%7d\n", i));

      //  printf("\n");
      //         printf("%d\n", printf("%+-d %d\n", i, i2));
      //      printf("%d\n", ft_printf("%+-d %d\n", i, i2));
      //   printf("\n");
      //         printf("%d\n", printf("% -d %d\n", i, i2));
      //      printf("%d\n", ft_printf("% -d %d\n", i, i2));
      //   printf("\n");
      //         printf("%d\n", printf("%+-7d %d\n", i, i2));
      //      printf("%d\n", ft_printf("%+-7d %d\n", i, i2));
      //   printf("\n");
      //         printf("%d\n", printf("% -7d %d\n", i, i2));
      //      printf("%d\n", ft_printf("% -7d %d\n", i, i2));
      //   printf("\n");
      //         printf("%d\n", printf("%+-07d %d\n", i, i2));
      //      printf("%d\n", ft_printf("%+-07d %d\n", i, i2));
      //   printf("\n");
      //         printf("%d\n", printf("% -07d %d\n", i, i2));
      //      printf("%d\n", ft_printf("% -07d %d\n", i, i2));
      //   printf("\n");
      //         printf("%d\n", printf("%+-07.5d %d\n", i, i2));
      //      printf("%d\n", ft_printf("%+-07.5d %d\n", i, i2));
      //   printf("\n");
      //         printf("%d\n", printf("% -07.5d %d\n", i, i2));
      //      printf("%d\n", ft_printf("% -07.5d %d\n", i, i2));
      //   printf("\n");        
      //         printf("%d\n", printf("%+-7.5d %d\n", i, i2));
      //      printf("%d\n", ft_printf("%+-7.5d %d\n", i, i2));
      //   printf("\n");        
      //         printf("%d\n", printf("% -7.5d %d\n", i, i2));
      //      printf("%d\n", ft_printf("% -7.5d %d\n", i, i2));
      //   printf("\n");        
      //         printf("%d\n", printf("%+-0.5d %d\n", i, i2));
      //      printf("%d\n", ft_printf("%+-0.5d %d\n", i, i2));
      //   printf("\n");        
      //         printf("%d\n", printf("% -0.5d %d\n", i, i2));
      //      printf("%d\n", ft_printf("% -0.5d %d\n", i, i2));
      //   printf("\n");        
      //         printf("%d\n", printf("%+-.5d %d\n", i, i2));
      //      printf("%d\n", ft_printf("%+-.5d %d\n", i, i2));
      //   printf("\n");        
      //         printf("%d\n", printf("% -.5d %d\n", i, i2));
      //      printf("%d\n", ft_printf("% -.5d %d\n", i, i2));
      //   printf("\n");        
      //         printf("%d\n", printf("%-.d %d\n", i, i2));
      //      printf("%d", ft_printf("%-.d %d\n", i, i2));

   
      
      //    len2 = printf("%#15x %#X %d\n", i, i, i);
      // len = ft_printf("%#15x %#X %d\n", i, i, i);
      //    len2 += printf("%07x %#X\n", i, i);
      // len += ft_printf("%07x %#X\n", i, i);
      //    len2 += printf("%#025x\n", INT16_MAX);
      // len += ft_printf("%#025x\n", INT16_MAX);
      //    len2 += printf("%#10.15x\n", INT16_MAX);
      // len += ft_printf("%#10.15x\n", INT16_MAX);
      //    len2 += printf("%#07x\n", INT16_MAX);
      // len += ft_printf("%#07x\n", INT16_MAX);
      //    len2 += printf("%#09.15X\t%#09.15x\t%X\t%x\n", INT16_MAX, INT16_MAX, INT16_MAX, INT16_MAX);
      // len += ft_printf("%#09.15X\t%#09.15x\t%X\t%x\n", INT16_MAX, INT16_MAX, INT16_MAX, INT16_MAX);
      //    len2 += printf("%X\n", INT16_MAX);
      // len += ft_printf("%X\n", INT16_MAX);
      //    len2 += printf("%#-10X\t%#x\t%#-15.10X\n", INT16_MAX, INT16_MAX, INT16_MAX);
      // len += ft_printf("%#-10X\t%#x\t%#-15.10X\n", INT16_MAX, INT16_MAX, INT16_MAX);
      //    len2 += printf("%#15X\t%.10X\n", INT16_MAX, INT16_MAX);
      // len += ft_printf("%#15X\t%.10X\n", INT16_MAX, INT16_MAX);
      // printf("len %d | len2 %d\n", len, len2);


        
         len2 = printf("\n%o\n", INT16_MAX);
        len = ft_printf("%o\n", INT16_MAX);
        printf("len %d | len2 %d\n", len, len2);
         len2 = printf("\n%#o\n", INT16_MAX);
        len = ft_printf("%#o\n", INT16_MAX);
        printf("len %d | len2 %d\n", len, len2);
         len2 = printf("\n%9o\n", INT16_MAX);
        len = ft_printf("%9o\n", INT16_MAX);
        printf("len %d | len2 %d\n", len, len2);
         len2 = printf("\n%09o\n", INT16_MAX);
        len = ft_printf("%09o\n", INT16_MAX);
        printf("len %d | len2 %d\n", len, len2);
         len2 = printf("\n%#9o\n", INT16_MAX);
        len = ft_printf("%#9o\n", INT16_MAX);
        printf("len %d | len2 %d\n", len, len2);
         len2 = printf("\n%#09o\n", INT16_MAX);
        len = ft_printf("%#09o\n", INT16_MAX);
        printf("len %d | len2 %d\n", len, len2);
         len2 = printf("\n%#.9o\n", INT16_MAX);
        len = ft_printf("%#.9o\n", INT16_MAX);  
        printf("len %d | len2 %d\n", len, len2);    
         len2 = printf("\n%15.9o\n", INT16_MAX);
        len = ft_printf("%15.9o\n", INT16_MAX);
        printf("len %d | len2 %d\n", len, len2);
         len2 = printf("\n%#15.9o\n", INT16_MAX);
        len = ft_printf("%#15.9o\n", INT16_MAX);
        printf("len %d | len2 %d\n", len, len2);
        
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

      //  int q = UINT64_MAX;
      // printf("% u\n", i);
      // printf("%+u\n", i);
      // unsigned long w = UINT32_MAX;
      // intptr_t p = UINT64_MAX;

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
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "includes/ft_printf.h"

#define PREFIX "0x"
/* #define H  (16)
#define HH (32)
#define L  (64)
#define LL (128) */
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

int main(void)
{   

    char *str = "adress pointer";
    char *str2 = "adress variable";
    char *str3 = "Nice day";
    char c = ':';
    
    int aa = 5;
    int *p = &aa;
    intptr_t nb = sizeof(intptr_t);

   int len;
   int len2;

   char *succes  = GRN "SUCCESS" RESET;
   char *fail  = RED "FAIL" RESET;

int test;
// file_checker tests
//    len = ft_printf("%5%");
//    printf("\n");
//    len2 = printf("%5%");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
//    len = ft_printf("%-5%");
//    printf("\n");
//    len2 = printf("%-5%");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
//    len = ft_printf("%.0%");
//    printf("\n");
//    len2 = printf("%.0%");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
//    len = ft_printf("%   %", "test");
//    printf("\n");
//    len2 = printf("%   %", "test");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
//    len = ft_printf("%x", 0);
//    printf("\n");
//    len2 = printf("%x", 0);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%X", 0);
//    printf("\n");
//    len2 = printf("%X", 0);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%x", 4294967296);
//    printf("\n");
//    len2 = printf("%x", 4294967296);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%X", 4294967296);
//    printf("\n");
//    len2 = printf("%X", 4294967296);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%x", test);
//    printf("\n");
//    len2 = printf("%x", test);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%hx", 4294967296);
//    printf("\n");
//   len2 = printf("%hx", 4294967296);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%hhX", 4294967296);
//    printf("\n");
//   len2 = printf("%hhX", 4294967296);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%#x", 0);
//    printf("\n");
//   len2 = printf("%#x", 0);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%s", "abc");
//    printf("\n");
//   len2 = printf("%s", "abc");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%s", "this is a string");
//    printf("\n");
//   len2 = printf("%s", "this is a string");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%s ", "this is a string");
//    printf("\n");
//   len2 = printf("%s ", "this is a string");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%s  ", "this is a string");
//    printf("\n");
//   len2 = printf("%s  ", "this is a string");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("this is a %s", "string");
//    printf("\n");
//   len2 = printf("this is a %s", "string");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("Line Feed %s", "\\n");
//    printf("\n");
//   len2 = printf("Line Feed %s", "\\n");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%10s is a string", "this");
//    printf("\n");
//   len2 = printf("%10s is a string", "this");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%-10s is a string", "this");
//    printf("\n");
//   len2 = printf("%-10s is a string", "this");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%s %s", "this", "is");
//    printf("\n");
//   len2 = printf("%s %s", "this", "is");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%s %s %s", "this", "is", "a");
//    printf("\n");
//   len2 = printf("%s %s %s", "this", "is", "a");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%s %s %s %s", "this", "is", "a", "multi");
//    printf("\n");
//   len2 = printf("%s %s %s %s", "this", "is", "a", "multi");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%s %s %s %s string. gg!", "this", "is", "a", "multi", "string");
//    printf("\n");
//   len2 = printf("%s %s %s %s string. gg!", "this", "is", "a", "multi", "string");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%s%s%s%s%s", "this", "is", "a", "multi", "string");
//    printf("\n");
//   len2 = printf("%s%s%s%s%s", "this", "is", "a", "multi", "string");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);

// len = ft_printf("@moulitest: %o", 0);
//    printf("\n");
//   len2 = printf("@moulitest: %o", 0);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("@moulitest: %.o %.0o", 0, 0);
//    printf("\n");
//   len2 = printf("@moulitest: %.o %.0o", 0, 0);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("@moulitest: %5.o %5.0o", 0, 0);
//    printf("\n");
//   len2 = printf("@moulitest: %5.o %5.0o", 0, 0);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("@moulitest: %#.o %#.0o", 0, 0);
//    printf("\n");
//   len2 = printf("@moulitest: %#.o %#.0o", 0, 0);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%+d", 0);
//    printf("\n");
//   len2 = printf("%+d", 0);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%-5d", 42);
//    printf("\n");
//   len2 = printf("%-5d", 42);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%-05d", 42);
//    printf("\n");
//   len2 = printf("%-05d", 42);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%hd", -32768);
//    printf("\n");
//   len2 = printf("%hd", -32768);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%hd", -32769);
//    printf("\n");
//   len2 = printf("%hd", -32769);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);

// len = ft_printf("%lld", -9223372036854775808);
//    printf("\n");
//   len2 = printf("%lld", -9223372036854775808);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%-10.5d", 4242);
//    printf("\n");
//   len2 = printf("%-10.5d", 4242);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("@moulitest: %.d %.0d", 0, 0);
//    printf("\n");
//   len2 = printf("@moulitest: %.d %.0d", 0, 0);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("@moulitest: %5.d %5.0d", 0, 0);
//    printf("\n");
//   len2 = printf("@moulitest: %5.d %5.0d", 0, 0);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%u", 0);
//    printf("\n");
//   len2 = printf("%u", 0);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%u", 4294967296);
//    printf("\n");
//   len2 = printf("%u", 4294967296);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);

// len = ft_printf("@moulitest: %#.x %#.0x", 0, 0);
//    printf("\n");
//   len2 = printf("@moulitest: %#.x %#.0x", 0, 0);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("@moulitest: %.x %.0x", 0, 0);
//    printf("\n");
//   len2 = printf("@moulitest: %.x %.0x", 0, 0);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);


// // len = ft_printf("%jx", -4294967297);
// //    printf("\n");
// //   len2 = printf("%jx", -4294967297);
// // printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%");
//    printf("\n");
//   len2 = printf("%");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("% ");
//    printf("\n");
//   len2 = printf("% ");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%Z");
//    printf("\n");
//   len2 = printf("%Z");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("% hZ");
//    printf("\n");
//   len2 = printf("% hZ");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("% hZ%");
//    printf("\n");
//   len2 = printf("% hZ%");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("% Z", "test");
//    printf("\n");
//   len2 = printf("% Z", "test");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("% Z ", "test");
//    printf("\n");
//   len2 = printf("% Z ", "test");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("% Z%s", "test");
//    printf("\n");
//   len2 = printf("% Z%s", "test");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%%%", "test");
//    printf("\n");
//   len2 = printf("%%%", "test");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%%   %", "test");
//    printf("\n");
//   len2 = printf("%%   %", "test");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%ll#x", 9223372036854775807);
//    printf("\n");
//   len2 = printf("%ll#x", 9223372036854775807);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%010s is a string", "this");
//    printf("\n");
//   len2 = printf("%010s is a string", "this");
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
// len = ft_printf("%05c", 42);
//    printf("\n");
//   len2 = printf("%05c", 42);
// printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);
len = ft_printf("%jd", -9223372036854775808);
   printf("\n");
  len2 = printf("%jd", -9223372036854775808);
printf("\n[%d == %d]: %s\n", len, len2, (len == len2) ? succes :  fail);












   // len2 = ft_printf("%-15.7s %% %-5c %-20p %% W%.s %c %p\n", str, c, &p, str2, c, p);
   //     len = printf("%-15.7s %% %-5c %-20p %% W%.s %c %p\n", str, c, &p, str2, c, p);
   
   // printf("len %d | len2 %d\n", len, len2);
   //    printf("\n\n");



   int i = -755;
   int i2 = 755;
   // float a = 0.42;
   // float a2 = -0.42;
   // float f = __FLT_MAX__;
   // float f2 = __FLT_MIN__;
   // double d = __DBL_MAX__;
   // double d2 = __DBL_MIN__;
   // long double dl = __LDBL_MAX__;
   // long double dl2 = __LDBL_MIN__;

   

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
      i = 15;
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

   
      
      //   len2 = printf("%#15x %#X %d\n", i, i, i);
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


        
      //    len2 = printf("%o\n", INT16_MAX);
      //   len = ft_printf("%o\n", INT16_MAX);
      //   printf("len %d | len2 %d\n", len, len2);
      //    len2 = printf("%#o\n", INT16_MAX);
      //   len = ft_printf("%#o\n", INT16_MAX);
      //   printf("len %d | len2 %d\n", len, len2);
      //    len2 = printf("%9o\n", INT16_MAX);
      //   len = ft_printf("%9o\n", INT16_MAX);
      //   printf("len %d | len2 %d\n", len, len2);
      //    len2 = printf("%09o\n", INT16_MAX);
      //   len = ft_printf("%09o\n", INT16_MAX);
      //   printf("len %d | len2 %d\n", len, len2);
      //    len2 = printf("%#9o\n", INT16_MAX);
      //   len = ft_printf("%#9o\n", INT16_MAX);
      //   printf("len %d | len2 %d\n", len, len2);
      //    len2 = printf("%#09o\n", INT16_MAX);
      //   len = ft_printf("%#09o\n", INT16_MAX);
      //   printf("len %d | len2 %d\n", len, len2);
      //    len2 = printf("%#.9o\n", INT16_MAX);
      //   len = ft_printf("%#.9o\n", INT16_MAX);  
      //   printf("len %d | len2 %d\n", len, len2);    
      //    len2 = printf("%15.9o\n", INT16_MAX);
      //   len = ft_printf("%15.9o\n", INT16_MAX);
      //   printf("len %d | len2 %d\n", len, len2);
      //    len2 = printf("%#15.9o\n", INT16_MAX);
      //   len = ft_printf("%#15.9o\n", INT16_MAX);
      //   printf("len %d | len2 %d\n", len, len2);
        
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

//       printf("-- NO MINUS --\n");
//          len2 = printf("%u\n", i);
//       len = ft_printf("%u\n", i);

//          len2 += printf("%0u\n", i);
//       len += ft_printf("%0u\n", i);

//          len2 += printf("%017u\n", i);
//       len += ft_printf("%017u\n", i);

//          len2 += printf("%.15u\n", i);
//       len += ft_printf("%.15u\n", i);

//          len2 += printf("%17.15u\n", i);
//       len += ft_printf("%17.15u\n", i);

//          len2 += printf("%0.15u\n", i);
//       len += ft_printf("%0.15u\n", i);

//          len2 += printf("%017.5u\n", i);
//       len += ft_printf("%017.5u\n", i);
// printf("len %d | len2 %d\n\n", len, len2);

//       printf("-- MINUS --\n");
//          len2 = printf("%-u %u\n", i, i);
//       len = ft_printf("%-u %u\n", i, i);

//          len2 += printf("%-0u %-0u\n", i, i);
//       len += ft_printf("%-0u %-0u\n", i, i);

//          len2 += printf("%-017u %-017u\n", i, i);
//       len += ft_printf("%-017u %-017u\n", i, i);

//          len2 += printf("%-.15u %-.15u\n", i, i);
//       len += ft_printf("%-.15u %-.15u\n", i, i);

//          len2 += printf("%-17.15u %-17.15u\n", i, i);
//       len += ft_printf("%-17.15u %-17.15u\n", i, i);

//          len2 += printf("%-0.15u %-0.15u\n", i, i);
//       len += ft_printf("%-0.15u %-0.15u\n", i, i);

//          len2 += printf("%-017.5u %-017.5u\n", i, i);
//       len += ft_printf("%-017.5u %-017.5u\n", i, i);
// printf("len %d | len2 %d\n\n", len, len2);



//          printf("%7u %u\n", i, i);
//       ft_printf("%7u %u\n", i, i);
//          printf("%-7u %u\n", i, i);
//       ft_printf("%-7u %u\n", i, i);
//          printf("%07u %u\n", i, i);
//       ft_printf("%07u %u\n", i, i);
//          printf("%.5u %u\n", i, i);
//       ft_printf("%.5u %u\n", i, i);
//          printf("%7.5u %u\n", i, i);
//       ft_printf("%7.5u %u\n", i, i);
//          printf("%-7.5u %u\n", i, i);
//       ft_printf("%-7.5u %u\n", i, i);
         
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
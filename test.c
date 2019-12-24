#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
 
void display(char* format, ...)
{
    int d; 
    double f;
    va_list factor;         // указатель на необязательный параметр
    va_start(factor, format);   // устанавливаем указатель
     
    for(char *c = format;*c; c++)
    {
        if(*c!='%')
        {
            write(1, &(*c), 1);
            // printf("%c", *c);
            continue;
        }
        switch(*++c)
        {
            case 'd': 
                d = va_arg(factor, int); 
                printf("%d", d);
                break;
            case 'f': 
                f = va_arg(factor, double);
                printf("%.2lf", f);
                break;
            default:
                printf("%c", *c);
        }
    }
    va_end(factor);
    // write(1, "\n", 1);
}
 
int main(void)
{   
    // display("Age:%d \t Weight:%f", 24, 68.4);

    int a = 10;
    int size_int = sizeof(a); // specifier 'dif'

    long b = 0123;
    int size_long = sizeof(b); // specifier 'dif'

    char c = 'z';
    int size_char = sizeof(c); // specifier 'c'

    char str[] = "011";
    int size_str = sizeof(*str); // specifier 's' ([])

    char *sptr = "012";
    int size_sptr = sizeof(*sptr); // specifier 's' (*)

    char *ptr = NULL;
    int size_ptr = sizeof(ptr); // specifier 's' (*)

    /* printf("size_int: %d\n", size_int);
    printf("size_long: %d\n", size_long);
    printf("size_char: %d\n", size_char);
    printf("size_str: %d\n", size_str);
    printf("size_sptr: %d\n", size_sptr);
    printf("size_ptr: %d\n", size_ptr);

    printf("test eror: %p\n", &ptr); */
    int signed_number = -5;
    int is_negative = signed_number < 0;
    double d = 5.8454;
    float f = 7.789654;
    
    printf("double: %.2f\n", d);

    /* int a = 4;
    int b = 2;
    // a &= b;
    a = a & b;
    printf("(a &= b) = %d\n", a); */


    
    return 0;
}
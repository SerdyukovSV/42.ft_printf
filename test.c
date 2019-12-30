#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int main(void)
{   
    
    int c = 0;
    // printf("c = %X\n", c);
    /* char cc = 255;
    printf("cc = %x\n", (unsigned char)cc);
    char ccc = 255;
    printf("ccc = %hhX\n", ccc); */

    /* int hex = 65;
    printf("hex = %D\n", hex);
    size_t q = 1;
    printf("q = %zu\n", sizeof(size_t)); */
    
    // << >>
    /* int a = 3;
    int b = 1;
    printf("%d >> %d = %d\n", a, b, a >> 1);
    printf("%d << %d = %d\n", a, b, 1 << a); */

    /* int a = 4;
    int b = 2;
    // a &= b;
    a = a & b;
    printf("(a &= b) = %d\n", a); */

    // attr->flags |= corres[specifier];
    // int a = -1;
    // a |= 32;
    // printf("-1 |= 32 = %d\n", a);

    char *str = "hello, world!";
    char *str2 = "Good job!";
    char *str3 = "Nice day";
    int i = 50;
    // char a = 250;
    char w;
    //printf("%0 10c %d\n", a, i);
    // printf("%2s %d %.s %c\n", str, i, str2, a);
    // printf("qwer %% %%qfwef qwdqwqwreqwfvrtjkfdlmserejhbeknlmrhbejnkwlmrbgijnklmecjrijntekmmerbrefkmwwrebgikw\nqwer %% %%qfwef qwdqwqwreqwfvrtjkfdlmserejhbeknlmrhbejnkwlmrbgijnklmecjrijntekmmerbrefkmwwrebgikw\nqwer %% %%qfwef qwdqwqwreqwfvrtjkfdlmserejhbeknlmrhbejnkwlmrbgijnklmecjrijntekmmerbrefkmwwrebgikw\nqwer %% %%qfwef qwdqwqwreqwfvrtjkfdlmserejhbeknlmrhbejnkwlmrbgijnklmecjrijntekmmerbrefkmwwrebgikw\nqwer %% %%qfwef qwdqwqwreqwfvrtjkfdlmserejhbeknlmrhbejnkwlmrbgijnklmecjrijntekmmerbrefkmwwrebgikw\nqwer %% %%qfwef qwdqwqwreqwfvrtjkfdlmserejhbeknlmrhbejnkwlmrbgijnklmecjrijntekmmerbrefkmwwrebgikw\nqwer %% %%qfwef qwdqwqwreqwfvrtjkfdlmserejhbeknlmrhbejnkwlmrbgijnklmecjrijntekmmerbrefkmwwrebgikw\nqwer %% %%qfwef qwdqwqwreqwfvrtjkfdlmserejhbeknlmrhbejnkwlmrbgijnklmecjrijntekmmerbrefkmwwrebgikw\nqwer %% %%qfwef qwdqwqwreqwfvrtjkfdlmserejhbeknlmrhbejnkwlmrbgijnklmecjrijntekmmerbrefkmwwrebgikw\nqwer %% %%qfwef qwdqwqwreqwfvrtjkfdlmserejhbeknlmrhbejnkwlmrbgijnklmecjrijntekmmerbrefkmwwrebgikw\nqwer %% %%qfwef qwdqwqwreqwfvrtjkfdlmserejhbeknlmrhbejnkwlmrbgijnklmecjrijntekmmerbrefkmwwrebgikw\nqwer %% %%qfwef qwdqwqwreqwfvrtjkfdlmserejhbeknlmrhbejnkwlmrbgijnklmecjrijntekmmerbrefkmwwrebgikw\nqwer %% %%qfwef qwdqwqwreqwfvrtjkfdlmserejhbeknlmrhbejnkwlmrbgijnklmecjrijntekmmerbrefkmwwrebgikw\n");
    // printf("qwer %% %%qfwef qwdqwqwreqwfvrtjkfdlmserejhbeknlmrhbejnkwlmrbgijnklmecjrijntekmmerbrefkmwwrebgikw\n");
    // printf("read char = %d\n", (ft_printf("%# 25s\n", str)));
    // ft_printf("%15s\n", str);
    // ft_printf("%20s\n", str);
    //ft_printf("%15.3s\n%-20.1s\n %s\n %-5c", str, str2, str3, w);
       printf("%15.3s\n%-20.1s\n %s\n %-5c", str, str2, str3, w);
    
    /* printf("HASH %d\n", HASH);
    printf("ZERO %d\n", ZERO);
    printf("MINUS %d\n", MINUS);
    printf("PLUS %d\n", PLUS);
    printf("SPACE %d\n", SPACE);
    printf("LOW_S_BIT %d\n", LOW_S_BIT);
    printf("UPP_S_BIT %d\n", UPP_S_BIT);
    printf("LOW_P_BIT %d\n", LOW_P_BIT);
    printf("LOW_D_BIT %d\n", LOW_D_BIT);
    printf("UPP_D_BIT %d\n", UPP_D_BIT);
    printf("LOW_I_BIT %d\n", LOW_I_BIT);
    printf("LOW_O_BIT %d\n", LOW_O_BIT);

    printf("UPP_O_BIT %d\n", UPP_O_BIT);
    printf("LOW_U_BIT %d\n", LOW_U_BIT);
    printf("UPP_U_BIT %d\n", UPP_U_BIT);
    printf("LOW_X_BIT %d\n", LOW_X_BIT);
    printf("UPP_X_BIT %d\n", UPP_X_BIT);
    printf("LOW_C_BIT %d\n", LOW_C_BIT);
    printf("UPP_C_BIT %d\n", UPP_C_BIT); */

    
    return 0;
}
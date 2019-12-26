#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

# define FT_BIT(x) (1 << (x))

# define HASH		(FT_BIT(0))
# define ZERO		(FT_BIT(1))
# define MINUS		(FT_BIT(2))
# define PLUS		(FT_BIT(3))
# define SPACE		(FT_BIT(4))
# define LOW_S_BIT	(FT_BIT(5))
# define UPP_S_BIT	(FT_BIT(6))
# define LOW_P_BIT	(FT_BIT(7))
# define LOW_D_BIT	(FT_BIT(8))
# define UPP_D_BIT	(FT_BIT(9))
# define LOW_I_BIT	(FT_BIT(10))
# define LOW_O_BIT	(FT_BIT(11))
# define UPP_O_BIT	(FT_BIT(12))
# define LOW_U_BIT	(FT_BIT(13))
# define UPP_U_BIT	(FT_BIT(14))
# define LOW_X_BIT	(FT_BIT(15))
# define UPP_X_BIT	(FT_BIT(16))
# define LOW_C_BIT	(FT_BIT(17))
# define UPP_C_BIT	(FT_BIT(18))
# define HH			(FT_BIT(19))
# define H			(FT_BIT(20))
# define LL			(FT_BIT(21))
# define L			(FT_BIT(22))
# define J			(FT_BIT(23))
# define Z			(FT_BIT(24))
# define WIDTH		(FT_BIT(25))
# define PRECISION	(FT_BIT(26))
# define LOW_B_BIT	(FT_BIT(27))

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
    int i = 50;
    printf("%6.5s\n", str);
        
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
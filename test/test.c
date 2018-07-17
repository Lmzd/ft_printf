#include <stdio.h>

int main(void)
{

    printf("Nombres positifs avec flag");
    printf("%d\n", 42);
    printf("+: %+d\n", 42);
    printf("-: %-d\n", 42);
    printf("#: %#d\n", 42);
    printf("0: %0d\n", 42);

    printf("Nombres négatifs avec flag");
    printf("%d\n", -42);
    printf("+: %+d\n", -42);
    printf("-: %-d\n", -42);
    printf("#: %#d\n", -42);
    printf("0: %0d\n", -42);

    printf("Nombres positifs avec options");
    printf("h: %hd\n", 42);
    printf("hh: %hhd\n", 42);
    printf("l: %ld\n", 42);
    printf("ll: %lld\n", 42);
    printf("j: %jd\n", 42);
    printf("z: %zd\n", 42);

    printf("Nombres negatifs avec options");
    printf("h: %hd\n", -42);
    printf("hh: %hhd\n", -42);
    printf("l: %ld\n", -42);
    printf("ll: %lld\n", -42);
    printf("j: %jd\n", -42);
    printf("z: %zd\n", -42);

    printf("Nombres positifs avec options et flag");
    printf("h: %hd\n", 42);
    printf("hh: %+hhd\n", 42);
    printf("l: %+ld\n", 42);
    printf("ll: %+lld\n", 42);
    printf("j: %+jd\n", 42);
    printf("z: %+zd\n", 42);

    printf("Nombres negatifs avec options et flag");
    printf("h: %+hd\n", -42);
    printf("hh: %+hhd\n", -42);
    printf("l: %+ld\n", -42);
    printf("ll: %+lld\n", -42);
    printf("j: %+jd\n", -42);
    printf("z: %+zd\n", -42);

    printf("int : %04.3f", 2.45354);
}
#include <stdio.h>
static int a;
extern int b;

extern void ext();

void bar()
{
    a = 1;
    b = 2;
}

void main()
{
    printf("x");
    bar();
    ext();
}

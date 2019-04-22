#include <stdio.h>

namespace myname{
    int var=42;
}

extern "C" {
    double ZN6myname3varE;
}

int main()
{
    printf("%d\n", ZN6myname3varE);
    return 0;
}
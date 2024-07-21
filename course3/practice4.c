#include <stdio.h>

int main()
{
    int a = 1, b = 2, c = 3, d = 4, max;
    if (a > b)
        max = a;
    else
        max = b;
    printf("max(a,b) = %d\n", max);
    // this expression also equal to under one.
    

    max = (c > d ? c : d);
    printf("max(c,d) = %d\n", max);
    return 0;
}
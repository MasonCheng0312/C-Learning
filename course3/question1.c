#include <stdio.h>

int main(){
    int i = 0, a = 0, b = 2, c = 3, d = 4;
    i = a++ && ++b && d++;
    printf("a = %d\n",a);
    printf("b = %d\n",b);
    printf("c = %d\n",c);
    printf("d = %d\n",d);

    // what is the output of a b c d ?
    // answer = 1, 2, 3, 4
    // why?
    // because && is "and" operator, and "a++" means use a before ++
    // so the result of a = 0 && ... is 0, which doesn't matter what value of other parameter after &&
    // ++b and d++ will not been run in this case.


    return 0;
}
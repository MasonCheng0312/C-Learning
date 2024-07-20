#include <stdio.h>
// use "Exclusive or" to solve this question
void swap_without_tmp(int* a, int* b){
    // printf("a = %d",*a);
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}


int main(){
    int a = 3, b=5;
    swap_without_tmp(&a, &b);

    printf("a = %d\n",a);
    printf("b = %d\n",b);
    return 0;
}
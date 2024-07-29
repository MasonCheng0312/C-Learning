# include <stdio.h>

int Add(int x, int y){
    return x + y;
}

int main(){
    int a = 3;
    int b = 5;
    int answer = Add(a,b);

    // what is the address of function?

    printf("%p\n",&Add);
    printf("%p\n",Add);
    // both correct

    // but how should we create a pointer parameter for function?
    int (*p)(int,int) = Add;
    
    // then how to use this pointer? 
    printf("%d", (*p)(a,b));
     
    return 0;
}
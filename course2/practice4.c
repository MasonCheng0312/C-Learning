#include <stdio.h>

int get_fib_by_recursion(int target){
    if(target <= 2)return 1;
    return get_fib_by_recursion(target - 1) + get_fib_by_recursion(target - 2);
    // 這種算法的效能非常糟糕，因為有太多的重複計算。
    // 使用loop從前往後算則不會有重複計算的問題，可以提升效能。
}

int get_fib_by_loop(int target){
    int a = 1;
    int b = 1;
    int c = 1;
    while(target>2){
        c = a + b;
        a = b;
        b = c;
        target--;
    }
    return c;
}

int main(){
    int user_input;
    printf("please input a integer n and get n'th element of Fibonacci number\n");
    scanf("%d",&user_input);
    printf("answer = %d",get_fib_by_recursion(user_input));
    return 0;
}
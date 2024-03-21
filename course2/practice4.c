#include <stdio.h>

int get_fib(int target){
    if(target <= 2)return 1;
    return get_fib(target - 1) + get_fib(target - 2);
}

int main(){
    int user_input;
    printf("please input a integer n and get n'th element of Fibonacci number\n");
    scanf("%d",&user_input);
    printf("answer = %d",get_fib(user_input));
    return 0;
}
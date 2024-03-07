#include <stdio.h>

int compute_factorial(int target_num){
    int result = 1;
    for(int i = 1; i < (target_num+1); i++){
        result = result * i;
    }
    return result;
}

int main(){
    int answer = 0;
    for(int k = 1; k < 11; k++){
        answer = answer + compute_factorial(k);
    }
    printf("The answer of 1!+2!+...+10! is %d",answer);
    return 0;
}
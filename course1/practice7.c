#include <stdio.h>

int try_devide_method(int target){
    for(int i = 2;i<target;i++){
        if(target % i == 0){
            return 0;
        }
        else if(i == (target-1)){return 1;}
        else{continue;}        
    }
}

int main(){
    int user_input;
    printf("input a number and I'll check if it is prime number\n");
    scanf("%d",&user_input);
    if(try_devide_method(user_input)){
        printf("%d is a prime number\n",user_input);
    }
    else{
        printf("%d is not a prime number\n",user_input);
    }
    return 0;
}
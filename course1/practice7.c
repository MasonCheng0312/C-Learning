#include <stdio.h>
#include <math.h>

int try_devide_method(int target){
    //試除法，O(n)
    for(int i = 2;i<target;i++){
        if(target % i == 0){
            return 0;
        }
        else if(i == (target-1)){return 1;}     
    }
}

int squareRoot_method(int target){ 
    // 平方根法，假定一數a並非質數，則必可被分解為a = b * c ，且b&C <= a^(1/2) (等號成立於b = c，a為完全平方數)
    // 相比試除法(暴力解)大幅減少計算量，複雜度O(n^(1/2))
    for(int i = 2;i<=sqrt(target);i++){
        if (target % i == 0){
            return 0;
        }
        else if (i >= sqrt(target)){
            return 1;
        }
    }
}

int main(){
    int user_input;
    printf("input a number and I'll check if it is prime number\n");
    scanf("%d",&user_input);
    // if(try_devide_method(user_input)){
    //     printf("%d is a prime number\n",user_input);
    // }
    // else{
    //     printf("%d is not a prime number\n",user_input);
    // }
    if(squareRoot_method(user_input)){
        printf("%d is a prime number\n",user_input);
    }
    else{
        printf("%d is not a prime number\n",user_input);
    }
    return 0;
}
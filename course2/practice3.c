# include <stdio.h>

int factorial(int target){
    if(target <= 1){
        return 1;
    }
    return target * factorial(target-1);
}

int main(){
    int user_input;
    printf("please input a integer and get its factorial result\n");
    scanf("%d",&user_input);
    printf("answer = %d",factorial(user_input));
    return 0;
}
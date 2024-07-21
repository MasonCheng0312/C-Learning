#include <stdio.h>

int count_NumOf1_in_binary(int a){
    int count = 0;
    for(int i = 0; i < 32; i++){
        if((a>>i)&1 == 1){
            count++;
        }
    }
    return count;
}


int main(){
    int user_input;
    printf("please input an integer: \n");
    scanf("%d",&user_input);
    int result = count_NumOf1_in_binary(user_input);
    printf("answer = %d",result);
    return 0;
}
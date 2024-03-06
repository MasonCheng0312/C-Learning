#include <stdio.h>

int main(){
    int temp = 1;
    int input = 0;
    printf("please input a interger and I will compute factorial.");
    scanf("%d",&input);
    for(int i = 1; i<(input+1); i++){
        temp = temp * i;
    }
    printf("the result is %d",temp);
    return 0;   
}
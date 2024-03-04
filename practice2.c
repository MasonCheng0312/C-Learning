#include <stdio.h>

int main(){
    printf("**********start*********\n");

    for(int i = 1 ; i<=100 ; i++){
        if(1 == i%2){
            printf("%d\n",i);
        }
    }
    printf("**********finish*********\n");
    return 0;
}
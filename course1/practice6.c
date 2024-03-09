#include <stdio.h>

int main(){
    char arr[] ="hello world";
    char result[12] = {0};
    for(int x;x<12;x++){
        result[x] = '*';
    }

    for(int i = 0, k = 11; i<6; i++,k--){
        result[i] = arr[i];
        result[k] = arr[k];

        for(int j=0;j<12;j++){
            printf("%c",result[j]);
        }
        printf("\n");
    } 

    return 0;
}
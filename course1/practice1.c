#include <stdio.h>

int main(){
    int user_input;
    printf("please input an interger.");
    scanf("%d",&user_input);
    
    if (user_input%2 == 1){
        printf("your input is odd.");
    }
    else {
        printf("your input is even.");
    }
    return 0;
}
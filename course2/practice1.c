#include <stdio.h>

void print(unsigned int input){
    if (input > 9)
    {
        print(input/10);
        printf("%d ",input%10);
    }
    else printf("%d ",input);

}

int main(){
    unsigned int input;
    printf("please input an integer and the code will print it in order.\n");
    scanf("%d",&input);
    print(input);
    return 0;
}
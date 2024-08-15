#include <string.h>
#include <stdio.h>

void my_strcat(char* dest, char* source){
    while (*dest)
    {
        dest++;
    }
    while(*dest++ = *source++){
        ;
    }
}



int main(){
    char str1[12] = "Hello!";
    char str2[] = "world";
    // strcat(str1,str2);
    my_strcat(str1,str2);
    printf("%s",str1);
    // in older patch c IDE, this might be error because of space of str1 doesn't enough
    // the most conservative method is to init a bigger array and contain "\0" in it

    return 0; 
}
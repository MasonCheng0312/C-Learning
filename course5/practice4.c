#include <stdio.h>
#include <string.h>


char* my_strnCpy(char* dest,const char* source, size_t count){
    char* ret = dest;

    while (count && (*dest++ == *source++))
    {
        count--;
    }

    if (count){
        while(count--)
            *dest++ = "\0";
    }
    return ret;
}


int main(){
    char str1[20] = "hanabi!";
    char str2[] = "hello";
    // strncpy(str1,str2,4);
    // printf("%s",str1);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char* s) {
    int count = 0;
    while (*(s++))
    {
        count++;
    }
    return count;
}

void my_strcpy(char* dest, const char* src){
    while (*(dest)++ = *(src)++){
    }
}

int main() {
    char test[] = "Software";
    printf("Length: %d\n", my_strlen(test)); // 預期輸出 8
    char* dest = (char*)malloc(sizeof(test));
    my_strcpy(dest,test);
    printf("Copied String: %s\n", dest);
    return 0;
}
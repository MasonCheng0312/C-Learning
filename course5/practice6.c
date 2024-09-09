#include <string.h>
#include <stdio.h>

int main(){
    char str[] = "mason9003122001@gmail.com";
    char* sep = "@.";

    // because of strtok() will change the content in char array, so we must copy it

    char buffer[1024] = {0};
    strcpy(buffer,str);

    char* ret = NULL;
    // good example for use method of strtok()
    for(ret = strtok(buffer,sep);ret != NULL;ret = strtok(NULL,sep)){
        printf("%s\n",ret);
    }


    return 0;
}
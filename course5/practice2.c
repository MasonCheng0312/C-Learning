#include <string.h>
#include <stdio.h>
#include <assert.h>

char* my_strcpy(char* destination, char* source){
    char* ret = destination;

    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = *source; // copy '\0'

    return ret;
}


int main(){
    char example_strArray[] = "ohanabi";
    char example_copy[] = "ahoy";
    char* answer = strcpy(example_strArray,example_copy); // first argument is space, second one is for str we want to copy
    // space must be big enough for str!
    printf("now strArray is %s\n",answer);

    printf("now create my_strcpy()!\n");
    return 0;
}
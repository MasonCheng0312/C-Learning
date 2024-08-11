#include <string.h>
#include <stdio.h>
#include <assert.h>


int main(){
    char example_strArray[] = "ohanabi";
    char example_copy[] = "ahoy";
    strcpy(example_strArray,example_copy); // first argument is space, second one is for str we want to copy
    // space must be big enough for str!
    printf("now strArray is %s\n",example_strArray);
    return 0;
}
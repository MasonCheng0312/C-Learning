#include <string.h>
#include <stdio.h>

int main(){
    int str_len = strlen("abcde");
    printf("use strlen lib function for const. str abcde \n");
    printf("result is %d \n",str_len);
    // the principle of strlen() is to find "\0" and count element before "\0"(no include)
    char str_arr[] ={'a','b','c'};
    printf("use strlen lib function for str array with out '\\0'\n");
    printf("result is %d \n",strlen(str_arr)); 
    printf("this code is wrong and answer is random\n");
    return 0;
}
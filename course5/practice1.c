#include <string.h>
#include <stdio.h>
#include <assert.h>

int my_strlen(char* input){
    int count = 0;
    assert(input != NULL);
    while (*input){
        count++;
        input++;
    }
    return count;   
}


int main(){
    int str_len = strlen("abcde");
    printf("use strlen lib function for const. str abcde \n");
    printf("result is %d \n",str_len);
    // the principle of strlen() is to find "\0" and count element before "\0"(no include)

    char str_arr[] ={'a', 'b', 'c', 'd', 'e', '\0'};
    printf("use strlen lib function for str array with out '\\0'\n");
    printf("result is %d \n",strlen(str_arr)); 
    printf("this code is wrong and answer is random(can't init str array without \\0)\n");

    printf("use my_strlen() build ourself\n");
    printf("result is %d \n",my_strlen(str_arr));

    // now consider this situation:
    if (strlen("abc")-strlen("abcde") > 0)printf("why?\n");
    printf("because of return type of strlen() is size_t, which also called unsigned int\n");
    printf("and when we calculate two size_t num, the result always positive\n");
    
    return 0;
}
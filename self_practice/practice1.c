// This practice is trying to print string from outer to inner

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int main(){
    char arr[] = "COSBI bio lab is good";
    int input_str_len = strlen(arr); // strlen() gets the length of the string excluding the null terminator
    char print_result[input_str_len + 1];  // +1 for null terminator
    for(int x = 0; x < input_str_len; x++){
        print_result[x] = '*';
    } // initialize print_result with "*"

    print_result[input_str_len] = '\0'; // null terminate the string
    int init_step = (input_str_len % 2 == 0) ? 0:1;

    for(int step = 0; step <= (input_str_len/2); step++){
        int middle_index = (input_str_len + init_step) / 2;
        print_result[middle_index - step - 1] = arr[middle_index - step - 1];
        print_result[middle_index + step] = arr[middle_index + step];
        
        
        // for(int i = 0; i < input_str_len; i++){
        //     printf("%c", print_result[i]);
        // }
        // printf("\n");
        printf("%s\n", print_result);
        Sleep(300); 
        system("cls");   
    }
}
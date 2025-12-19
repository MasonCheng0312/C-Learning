#include <stdio.h>
char* longestCommonPrefix(char** strs, int strsSize) {  
    for(int char_index = 0;;char_index++){ 
        char standard = strs[0][char_index];              
        for(int menber_str_index = 0; menber_str_index < strsSize; menber_str_index++){
            char compare_char = strs[menber_str_index][char_index];
            if ((compare_char != standard) || (compare_char == '\0')){
                strs[0][char_index] = '\0';
                return strs[0];
            }
        }        
    }

}

int main(){
    char case1[] = "flower";
    char case2[] = "flow";
    char case3[] = "flight";
    char *test_strs[] = {case1,case2,case3}; 
    char* result = longestCommonPrefix(test_strs, 3);
    printf("the longest prefix is : %s\n",result);
}
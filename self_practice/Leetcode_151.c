#include <stdio.h>

void reverse(char* str, int sz){
    for(int i = 0; i < sz/2 ; i++){
        char tmp = *(str + i);
        *(str + i) = *(str + sz - 1 - i);
        *(str + sz - 1 - i) = tmp;
    }
}

int my_strlen(char* s){
    int count = 0;
    while(*(s++)){
        count++;
    }
    return count;
}

void delete_space(char* str){
    char* slow = str;
    char* fast = str;
    while(*fast != '\0'){
        while(*fast == ' ')fast++; // 遇到空格，*fast跳過

        // *fast找到字母了
        if(*fast != '\0'){
             // 如果真的有單字
            if(slow != str) *slow++ = ' '; // 非首字則補空格
            while(*fast != ' ' && *fast != '\0'){
                *slow++ = *fast++;
            }
        }
    }
    *slow = '\0';
}

char* reverseWords(char* s) { // 使用3個步驟來處理翻轉: 1. 整個字串翻轉 2. 針對每個word 翻轉 3.加上 '\0'
    delete_space(s);
    reverse(s, my_strlen(s));
    char* fast = s;
    char* slow = s;

    while(*fast != '\0'){
        slow = fast;
        if(*fast == ' '){
            fast++;
            slow++;
        }
        while(*fast != ' ' && *fast != '\0'){
            fast++;
        }
        reverse(slow, (fast - slow));

    }


    return s;
}

int main(){
    char str[] = " the sky  is blue  ";
    char* ans = reverseWords(str);
}
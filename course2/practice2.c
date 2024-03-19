# include <stdio.h>

int my_strlen(char* str){
    if (*str != '\0'){
        // C語言中單引號''代表字符，而雙引號""代表字串。
        // 比較是否等於'\0'時應是用*str而非pointer str。
        return my_strlen(str+1) + 1;
    }
    else return 0;
}

int main(){
    char input[] = "hello world";
    int len_of_char = my_strlen(input);
    printf("len = %d",len_of_char);
    return 0;
}
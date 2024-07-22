#include <stdio.h>

// char pointer
int main(){
    char ch = 'c';
    char* pt_ch = &ch;
    printf("pt_ch is %c\n",ch);

    char ch_arr[] = "rabbit";
    char* pt_chArr = ch_arr; // name of array is the first element address of this array 
    printf("ch array = %s\n", ch_arr); 
    printf("ch array = %s\n", pt_chArr);

    // or we can also use this form to init a char pointer which is a constant
    char* pt = "abcde";
    printf("pt = %s\n",pt);

    // *pt = "w";
    // printf("pt = %s\n",pt);
    return 0;
}

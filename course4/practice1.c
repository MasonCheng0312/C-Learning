#include <stdio.h>

// char pointer
int main(){
    char ch = 'c';
    char* pt_ch = &ch;
    printf("pt_ch is %c\n",ch);

    char ch_arr[] = "rabbit";
    char* pt_chArr = ch_arr; // name of array is the first element address of this array.
    printf("ch array = %s\n", ch_arr); 
    printf("ch array = %s\n", pt_chArr);

    // or we can also use this form to init a char pointer which is a constant.
    char* pt = "abcde";
    printf("pt = %s\n",pt);
    // *pt = "w"; Notice this syntax.
    // In some compiler, this bad syntax will build successfully.
    // but it isn't a legal form, why??
    // because as we just said, use pointer to initial a char array means it is a "constant",
    // then as the definition of constant, it shouldn't been changed.
    // so we should do more correctly to pretend our code from this.
    // const char* pt = "abcde"; 

    /*******************************************************************************************************************/
    //let's consider this case :
    char test1[] = "abcde";
    char test2[] = "alert";
    const char* result1 = (test1 == test2 ? "yes":"no");
    printf("if first address equal? Ans: %s\n",result1);
    // but if in this form :
    const char* test_pt1 = "abcde";
    const char *test_pt2 = "abcde";
    const char* result2 = (test_pt1 == test_pt2 ? "yes":"no");
    printf("if first address equal? Ans: %s\n",result2);
    // because of test_pt1, test_pt1 are both "constant", same value "abcde" doesn't need two different space to restore.

    /*******************************************************************************************************************/
    return 0;
}

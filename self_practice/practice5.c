// 題目：找出唯一出現一次的數字 陣列中有一堆數字，其中幾乎所有數字都出現了兩次，只有一個數字只出現了一次。
// 請不使用額外的陣列、不排序，找出那個落單的數字。

#include <stdio.h>

int main(){
    int nums[] = {4, 1, 2, 1, 2};
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = 0;
    for (int i = 0; i < size; i++) {
        result = result ^ nums[i];
    }

    printf("The single number is: %d\n", result); 
    return 0;
}
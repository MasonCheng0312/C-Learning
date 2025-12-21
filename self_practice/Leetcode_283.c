/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.*/

#include <stdio.h>

void moveZeroes1(int* nums, int numsSize) {
    for(int i = 0;i < numsSize; i ++){
        int* slow_pointer = nums + i ;
        int* fast_pointer = slow_pointer;
        if (*slow_pointer == 0){
            for(int j = 1; j < (numsSize - i); j++){
                if(*(fast_pointer + j) != 0){
                    *slow_pointer = *(fast_pointer + j);
                    *(fast_pointer + j) = 0;
                    break;
                } 
            }
        }
    }
} // O(N^2)的作法

void moveZeroes2(int* nums, int numsSize) {
    int* end = nums + numsSize;
    int* slow = nums;
    int* fast = nums;
    for(;fast < end; fast++){
        if (*fast != 0){
            int temp = *slow;
            *slow = *fast;
            *fast = temp;
            slow++;
        }
    }
} // O(N)的作法

int main(){
    int nums[] ={0,1,0,3,12};
    int size = 5;
    moveZeroes2(nums,size);

    for(int i = 0;i < size;i++){
        printf("result = %d\n",nums[i]);
    }
    
}
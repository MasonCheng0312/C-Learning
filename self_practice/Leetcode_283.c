/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.*/


void moveZeroes(int* nums, int numsSize) {
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


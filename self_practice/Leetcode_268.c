int missingNumber(int* nums, int numsSize) {
    int expected_sum = (1 + numsSize)*numsSize/2;
    int reality_sum = 0;
    for(int i = 0; i < numsSize; i++){
        reality_sum += *(nums + i);
    }
    return (expected_sum - reality_sum);     
}
int majorityElement(int* nums, int numsSize) {
    int target = *nums;
    int vote = 0;
    for(int i = 1; i < numsSize; i++){
        if(*(nums + i) == target){
            vote++;
        }
        else{
            if(--vote < 0){
                target = *(nums + i);
                vote = 0;
            }
        }
    }
    return target;
}
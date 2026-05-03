int removeElement(int* nums, int numsSize, int val) {
    int* end_place = (nums + numsSize - 1);
    int count_val = 0;
    for(int i = 0; i < numsSize; i++){
        while(end_place > (nums + i) && *end_place == val){
            end_place--;
            count_val++;
        }
        if((nums + i) > end_place)break;
        else if(*(nums + i) == val){
            int tmp = *(nums + i);
            *(nums + i) = *end_place;
            *end_place = tmp;
            end_place--;
            count_val++;
        }
    }
    return (numsSize - count_val);
}
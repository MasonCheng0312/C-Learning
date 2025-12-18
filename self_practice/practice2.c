// optimize the bubble sort function to stop early if the array is already sorted.
#include <stdio.h>

void BubbleSort(int* arr, int size){
    for(int current_index = 0; current_index < (size - 1); current_index++){
        int is_sorted = 1; // assume the array is sorted
        for(int compare_index = 0; compare_index < (size - 1 - current_index); compare_index++){
            if(arr[compare_index] > arr[compare_index + 1]){
                // swap
                int temp = arr[compare_index + 1];
                arr[compare_index + 1] = arr[compare_index];
                arr[compare_index] = temp;
                is_sorted = 0; // found an unsorted pair, so the array is not sorted
            }
            printf("Round %d, compare index %d: ", current_index + 1, compare_index + 1);
            for(int i = 0; i < size; i++){
                printf("%d ", arr[i]);
            }
            printf("\n");            
        }
        if(is_sorted) break;
    }
}


int main(){
    int origin_arr[10] = {4,3,10,9,8,6,5,7,2,1}; // this is the worst case for bubble sort.
    int size_of_arr = sizeof(origin_arr)/sizeof(origin_arr[0]);

    printf("Original array:\n");
    for(int i = 0; i < size_of_arr; i++){
        printf("%d ", origin_arr[i]);
    }
    printf("\n");

    BubbleSort(origin_arr, size_of_arr);

}
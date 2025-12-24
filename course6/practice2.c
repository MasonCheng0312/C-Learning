// in this practice we will do some exam of malloc() calloc() realloc() free()
#include <stdlib.h>
#include <stdio.h>

int** create_matrix(int rows, int cols){
    int** ret = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++){
        *(ret + i) = (int*)calloc(cols, sizeof(int)); 
    }
    return ret;
}

void free_matrix(int** matrix, int rows) {
    for(int i = 0; i < rows; i++){
        free(*(matrix + i));
    }
    free(matrix);
}

int* integer_array_initCreator(int size){
    int* pt = (int*)malloc(size * sizeof(int));
    if(pt == NULL){
        return pt;
    } 

    for(int i = 0; i < size; i++){
        *(pt + i) = (i + 1);
    }
    return pt;
}

int main(){ 
    // test1 init integer array 
    int test = 10;
    int* first_int_pt = integer_array_initCreator(test);
    if(first_int_pt == NULL){printf("Space doesn't enough !");}
    else{
        printf("%d\n",*first_int_pt);
        printf("%d\n",*(first_int_pt + 1));
        free(first_int_pt);
        first_int_pt = NULL;  
    }
    
    // test2 append
    int test2 = 5;
    int* test2_arr = integer_array_initCreator(test2);
    int test2_sixth_element = 100;
    int* new_address = realloc(test2_arr,6 * sizeof(int));
    if(new_address != NULL){
        test2_arr = new_address;
        *(test2_arr + 5) = test2_sixth_element;
        printf("%d",*(test2_arr + 5));
    }
    else{
        printf("Space doesn't enough !");
    }
    free(test2_arr);
    
    return 0;
}
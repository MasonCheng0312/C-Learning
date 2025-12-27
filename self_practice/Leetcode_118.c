/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** ret = (int**)malloc(numRows * sizeof(int*));  
    for(int i = 0; i < numRows; i++){
        int row_element_counts = (i+1);
        ret[i] = (int*)malloc(row_element_counts * sizeof(int));
        for(int j = 0; j < row_element_counts; j++){
            if(j == 0 || j == (row_element_counts -1)){
                ret[i][j] = 1;
            }
            else{
                ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
            }
        }
    }
    *returnSize = numRows;
    *(returnColumnSizes) = (int*)malloc(numRows * sizeof(int));    
    for(int i = 0; i < numRows; i++){
        (*returnColumnSizes)[i] = i + 1;
    }
    return ret;
}
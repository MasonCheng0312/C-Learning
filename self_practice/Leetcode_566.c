/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int count_element = *(matColSize)*matSize;
    int m = matSize;
    int n = matColSize[0];

    if(r * c != count_element){ // if count of matrix element doesn't equal, return origin array
        *(returnSize) = matSize;
        *returnColumnSizes = (int*)malloc(sizeof(matSize*sizeof(int)));
        for(int i = 0; i < matSize; i++){
            **(returnColumnSizes + i) = matColSize[i];
        } 
        return mat;
    }

    else{
        int** ret_arr = (int**)malloc(r * sizeof(int*));
        // if(ret_arr == NULL) 其實應該要做安全防護，但在leetcode中故忽略
        for(int i = 0; i < r; i++){
            *(ret_arr + i) = (int*)malloc(c * sizeof(int));
        }
        for(int i = 0; i < count_element; i++){
            (ret_arr)[i/c][i%c] = mat[i/n][i%n];
        }
        *returnSize = r;
        *returnColumnSizes = (int*)malloc(r * sizeof(int));
        for(int i = 0; i < r; i++){
            **(returnColumnSizes + i) = c; 
        }
        return ret_arr;
    }

}   
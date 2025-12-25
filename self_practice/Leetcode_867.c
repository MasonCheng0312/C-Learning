/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int new_m = *(matrixColSize);
    int new_n = matrixSize;
    int** ret = (int**)malloc(matrixColSize[0] * sizeof(int*));
    for(int i = 0; i < new_m; i++){
        *(ret + i) = (int*)malloc(new_n * sizeof(int));
        for(int j = 0; j < new_n; j++){
            (*(ret + i))[j] = matrix[j][i];
        }
    }

    *returnSize = new_m;
    *(returnColumnSizes) = (int*)malloc(new_m * sizeof(int));
    for(int i = 0; i < new_m; i++){
        (*(returnColumnSizes))[i] = new_n;
    }

    return ret;

}
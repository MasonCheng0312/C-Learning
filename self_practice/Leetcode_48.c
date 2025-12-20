/*
48. Rotate Image : 
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation. */


void rotate(int** matrix, int matrixSize, int* matrixColSize) {

    // 對角線翻轉
    for(int i = 0; i< matrixSize; i++){
        for(int j = i + 1; j< matrixSize; j++){

           *(*(matrix + i) + j) = *(*(matrix + i) + j) ^ *(*(matrix + j) + i);
           *(*(matrix + j) + i) = *(*(matrix + i) + j) ^ *(*(matrix + j) + i);
           *(*(matrix + i) + j) = *(*(matrix + i) + j) ^ *(*(matrix + j) + i);

        }
    }

    // 左右翻轉 
    for(int i = 0; i < matrixSize; i++){        
        int* row_array = *(matrix + i); 
        for(int j = 0; j < (matrixSize/2); j++){
            int mirror_index = matrixSize - j - 1;
            if(mirror_index != j){
                row_array[j] = row_array[j] ^ row_array[mirror_index];
                row_array[mirror_index] = row_array[j] ^ row_array[mirror_index];
                row_array[j] = row_array[j] ^ row_array[mirror_index];
            }
        }
    }
}
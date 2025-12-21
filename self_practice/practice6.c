//Array Decay & Pointers

#include <stdio.h>

// 任務 1: 接收 int matrix[2][3] 這種連續記憶體

void print_flat_matrix(int (*arr)[3] , int rows) {
    printf("Flat Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            // 請試著用 "指標算術" 的方式印出，不要用 arr[i][j]
            printf("%d ", *(*(arr + i) + j)); 
        }
        printf("\n");
    }
}

// 任務 2: 接收 int* matrix[2] 這種指標陣列 (每一列可以在不同記憶體位置)
void print_jagged_matrix(int** arr, int rows, int cols) {
    printf("Jagged Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // 1. 連續的二維陣列
    int flat[2][3] = {{1, 2, 3}, {4, 5, 6}};
    
    // 2. 指標陣列 (模擬不連續記憶體，雖然這裡字串常數可能是連續的)
    int r1[] = {10, 20, 30};
    int r2[] = {40, 50, 60};
    int* jagged[] = {r1, r2};

    // 呼叫測試
    // 這裡如果不對應正確的宣告，編譯器會報 Warning: incompatible pointer type
    print_flat_matrix(flat, 2);
    print_jagged_matrix(jagged, 2, 3);

    return 0;
}
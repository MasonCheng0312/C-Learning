int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    // 1. 記憶體配置 (Memory Allocation)
    int** ret = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    *returnSize = n;
    
    for(int i = 0; i < n; i++) {
        ret[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    // 2. 定義邊界 (Boundaries)
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1; // 當前要填入的數字

    // 3. 螺旋填值 (Spiral Loop)
    while (num <= n * n) {
        
        // Step A: 向右 (Left -> Right)
        // 使用 <= right，填滿這一整列
        for (int i = left; i <= right && num <= n*n; i++) {
            ret[top][i] = num++;
        }
        top++; // 上邊界往下壓

        // Step B: 向下 (Top -> Bottom)
        // 注意：因為上面 top 已經 ++ 了，所以這裡不會重複填右上角那格
        for (int i = top; i <= bottom && num <= n*n; i++) {
            ret[i][right] = num++;
        }
        right--; // 右邊界往左縮

        // Step C: 向左 (Right -> Left)
        for (int i = right; i >= left && num <= n*n; i--) {
            ret[bottom][i] = num++;
        }
        bottom--; // 下邊界往上抬

        // Step D: 向上 (Bottom -> Top)
        for (int i = bottom; i >= top && num <= n*n; i--) {
            ret[i][left] = num++;
        }
        left++; // 左邊界往右縮
    }
    
    return ret;
}
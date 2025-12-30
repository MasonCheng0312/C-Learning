#include <stdio.h>

void print_binary(unsigned char n) {
    printf("0b");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i == 4) printf(" ");
    }
    printf(" (Hex: 0x%X)\n", n);
}

int main() {
    // 1. 模擬硬體目前的狀態 (亂七八糟的舊數值)
    // 1010 1011 (Clock Source 目前是 010，也就是 2)
    unsigned char TMR_CTRL = 0xAB; 
    
    printf("Original: ");
    print_binary(TMR_CTRL);

    // ==========================================
    // 請在下方開始你的 Read-Modify-Write 操作
    // 目標：將 Bit [6:4] 修改為 3 (011)
    // ==========================================

    // Step 1: 準備 Mask (遮罩) 
    // 提示：寬度是 3 bits，起始位置是 4
    unsigned char mask = ~(7 << 4);
    
    // Step 2: 清除舊資料 (Clear)
    
    TMR_CTRL &= mask; 
    // Step 3: 設定新資料 (Set)
    // 目標數值是 3
    TMR_CTRL |= (3 << 4);

    // ==========================================
    
    printf("Result:   ");
    print_binary(TMR_CTRL);
    
    // 驗算：
    // 原本 Bits [6:4] 是 010 (2)
    // 我們要改成 011 (3)
    // 其他位保持不變
    // 原本: 1 010 1011
    // 預期: 1 011 1011 -> 0xBB
    
    return 0;
}
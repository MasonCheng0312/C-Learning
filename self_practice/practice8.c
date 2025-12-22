#include <stdio.h>

// Q1: 請寫一個巨集 (Macro) 來計算陣列元素的個數
// 提示：總大小 / 單個元素大小
#define LEN(arr) (sizeof(arr)/sizeof(arr[0]))

// 參數說明：
// base: 陣列起始位址
// count: 陣列有幾個元素
// size: 每個元素佔幾個 byte (stride)
// offset: 我們想看該元素內的第幾個 byte
void print_nth_byte(void* base, int count, int size, int offset) {
    printf("Bytes at offset %d: ", offset);
    
    for (int i = 0; i < count; i++) {
        // Q2: 這是最關鍵的一步！
        // 我們要找到「第 i 個元素」的「起始位址」。
        // 提示：void* 不能直接加減，必須轉成能以 1 byte 移動的指標。
        char* target_addr = (char*)base + (i * size);
        
        // Q3: 拿到 target_addr 後，我們要往後移動 offset 個 byte，並取出該值。
        // 注意：我們要印出的是 unsigned char (00~FF)
        unsigned char val = *(unsigned char*)(target_addr + offset);
        
        printf("%02X ", val);
    }
    printf("\n");
}

int main() {
    // 測試 1: Int 陣列 (Little Endian 系統下: 0x00000001)
    int nums[] = {1, 258}; // 1 = 0x01, 258 = 0x0102
    // 記憶體 (Hex): [01 00 00 00] [02 01 00 00] ...
    
    printf("Int Array (Offset 0): ");
    print_nth_byte(nums, LEN(nums), sizeof(int), 0); 
    // 預期輸出: 01 02 (取出每個 int 的最低位 byte)

    printf("Int Array (Offset 1): ");
    print_nth_byte(nums, LEN(nums), sizeof(int), 1); 
    // 預期輸出: 00 01 (取出每個 int 的次低位 byte)

    return 0;
}
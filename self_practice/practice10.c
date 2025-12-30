#include <stdio.h>

// --- 你的任務：填空 ---

// 1. 設定變數 x 的第 n 位元為 1
#define SET_BIT(x, n) (x |= (1 << n))

// 2. 清除變數 x 的第 n 位元為 0
#define CLR_BIT(x, n) (x &= ~(1 << n))

// 3. 檢查變數 x 的第 n 位元 (如果該位是 1 回傳非 0，是 0 回傳 0)
#define CHK_BIT(x, n) (x & (1 << n))

// 4. 將變數 x 的第 n 位元進行反轉
#define FLIP_BIT(x, n) (x ^= (1 << n))

// --- 模擬情境：智慧家電控制暫存器 ---
// 假設這是一個 8-bit 的硬體暫存器 (Register)
// Bit 0: 電源 (Power) - 1:開, 0:關
// Bit 1: 風扇 (Fan)   - 1:轉, 0:停
// Bit 2: 睡眠模式 (Sleep) - 1:開, 0:關

void print_status(unsigned char reg) {
    printf("[Status] Power: %s | Fan: %s | Sleep: %s\n",
           CHK_BIT(reg, 0) ? "ON" : "OFF",
           CHK_BIT(reg, 1) ? "Spinning" : "Stopped",
           CHK_BIT(reg, 2) ? "Active" : "Inactive");
}

int main() {
    unsigned char ac_ctrl = 0; // 初始狀態：全關
    
    printf("--- Init ---\n");
    print_status(ac_ctrl);

    // 1. 使用 SET_BIT 打開電源 (Bit 0)
    printf("\n--- Turn Power ON ---\n");
    SET_BIT(ac_ctrl, 0);
    print_status(ac_ctrl);

    // 2. 使用 SET_BIT 打開風扇 (Bit 1)
    printf("\n--- Turn Fan ON ---\n");
    SET_BIT(ac_ctrl, 1);
    print_status(ac_ctrl);

    // 3. 使用 CLR_BIT 關閉風扇 (Bit 1)
    printf("\n--- Turn Fan OFF ---\n");
    CLR_BIT(ac_ctrl, 1);
    print_status(ac_ctrl);

    // 4. 使用 CHK_BIT 檢查：如果電源是開的，就打開睡眠模式 (Bit 2)
    printf("\n--- Logic Check ---\n");
    if (CHK_BIT(ac_ctrl, 0)) {
        printf("Power is ON, activating Sleep Mode...\n");
        SET_BIT(ac_ctrl, 2);
    }
    print_status(ac_ctrl);

    return 0;
}
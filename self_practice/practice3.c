// Try to use Operator to solve hardware status control problem
// Question : if we have an 8-bit variable to control the machine, different bit would control diff function.
// bit 0 : 1 for power on, 0 for power off
// bit 1 : 1 for warning ring, 0 for silence
// bit 4 : 1 for fan on, 0 for off

// mission : 
// 宣告 unsigned char status = 0;。
// 使用 | 開啟電源與風扇。
// 使用 & 檢查電源是否開啟，如果是，印出 "Power is ON"。
// 使用 & 與 ~ 關閉風扇。
#include <stdio.h>

void power_on(unsigned char* status){
    *status = *status | 1;
}

void fan_on(unsigned char* status){
    *status = *status | (1 << 4);
}

void fan_off(unsigned char* status){
    *status = *status & ~(1 << 4);
}

void power_is_on(unsigned char* status){
    if(*status & 1){
        printf("Power is ON\n");
    }
}


int main(){
    unsigned char status = 0;
    power_on(&status);
    fan_on(&status);
    power_is_on(&status);
    fan_off(&status);
}
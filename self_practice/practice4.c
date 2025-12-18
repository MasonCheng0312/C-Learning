// 場景： 在電腦圖學中，一個顏色通常由 RGBA 四個通道組成，每個通道佔 8-bit，剛好組成一個 32-bit 的整數 (unsigned int)。
// 格式：0xRRGGBBAA (例如：0xFF5733FF)
// 任務： 寫一個程式，給定一個 32-bit 顏色值，提取出各個通道的值

#include <stdio.h>

int main(){
    unsigned int pixel = 0xFF5733AA; // R=FF, G=57, B=33, A=AA

    unsigned char r = (pixel >> 24) & 0xFF;
    unsigned char g = (pixel >> 16) & 0x00FF;
    unsigned char b = (pixel >> 8) & 0x0000FF;
    unsigned char a = pixel & 0x000000FF;
    // 事實上寫0xFF就可以了，目標是取最後8bit

    printf("R: %X, G: %X, B: %X, A: %X\n", r, g, b, a);
}

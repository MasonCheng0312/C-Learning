#include <limits.h>

int myAtoi(char* s) {
    int sign = 1;
    long ret = 0;
    // first step : ignore front space
    while((*s) == ' ')s++;
    // second step : 
    if(*s == '+' || *s == '-'){
        if (*s == '-') sign = -1;
        s++;
    }
    // loop get integer
    while (*s >= '0' && *s <= '9')
    {
        int dig = *s - '0';
        ret = ret * 10 + dig;
        if (ret > INT_MAX) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        s++;
    }
    ret = (ret * sign);
    return (int)ret;
}
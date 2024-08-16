#include <string.h>
#include <stdio.h>

char* my_strstr(const char* str, const char* target){
    if (*str == '\0'){
        return (char*)str;
    }

    char* s1 = str;
    char* s2 = target;
    char* current = str;


    while (*current)
    {
        s1 = current;
        s2 = target;
        while((*s1 == *s2) && (*s1 != '\0') && (*s2 != '\0')){
            s1++;
            s2++;
        }
        if(*s2 == '\0'){
            return current;
        }       
        current++;        
    }
    return NULL;
    

}


int main(){
    char *p1 = "OshiNoKoGaSuki";
    char *target = "Suki";
    char* ret = my_strstr(p1,target);
    return 0;
}
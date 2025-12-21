// try to create my_memcpy() to realize function of memcpy()

#include <string.h>
#include <stdio.h>

void my_memcpy(void* dest, void* source, size_t size){
    // we should use const void* source to make input string is Read-only.
    char* src = (char*)source;
    char* des = (char*)dest;
    char* end_pt = des + size;
    while (des < end_pt)
    {
        *des = *src ;
        des++;
        src++;
    }
}
// memcpy doesn't secure correction of the condition that if source and dest has partial overlapping.
// memmove can do this

int main(){
    int source[] = {1, 2, 3, 4, 5};
    int dest[10] = {0};
    my_memcpy(dest, source, sizeof(source));
    for(int i = 0; i < 10; i++){
        printf("%d ",dest[i]);
    }
    printf("\n");
    return 0;
}



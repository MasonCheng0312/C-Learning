#include <assert.h>
#include <stdio.h>

void* my_memCpy(void* dest, const void* source, size_t sz){
    assert(dest != NULL);
    assert(source != NULL);
    void* ret = dest;

    while (sz--)
    {
        *(char*)dest = *(char*)source;
        (char*)dest++;
        (char*)source++;
    }

    return ret;
}


int main(){
    int arr1[] = {1,2,3,4};
    int arr2[10] = {0};
    my_memCpy(arr2,arr1,sizeof(arr1));
    printf("%d\n",arr2[0]);
    return 0;
}
#include <stdio.h>

void bubble_sort(int arr[], int sz)
{
    // parameter form: "arr[]" means the first element's address in this array, equals to int* arr[0].
    // because of it is a pointer, we can't calculate array's size in function.
    // with input parameter is a pointer, so this function can change value with address.
    // then the return type of this function is been set to void.
    for (int x = 0; x < (sz - 1); x++)
    {
        for (int y = 0; y < (sz - 1 - x); y++)
        {
            if(arr[y]>arr[y+1]){
                int tmp = arr[y+1];
                arr[y+1] = arr[y];
                arr[y] = tmp;
            }
        }
    }
}

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int sz = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, sz);
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
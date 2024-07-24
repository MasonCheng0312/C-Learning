#include <stdio.h>

int main()
{
    // pointer array & array pointer?
    /* 數組指針，顧名思義為一指向數組的指針。 */
    /* 指針數組，存放指針的數組。 */
    // for example
    int *p1[10];
    // 首先我們看到p1與[]結合，故p1為一數組(初始化的優先級 "[]" > "*")
    // 接著看到array所存放的類型為int*，故我們知道p1為一存放整數指針的數組。

    int(*p2)[10];
    // 由於優先級的問題(同上)，當我們要初始化數組指針時應用括號先讓變數名稱與*結合，確定他為一指針。
    // for example
    int arr[5] = {1, 2, 3, 4, 5};
    int(*p3)[5] = &arr;
    // another example
    char *arr2[4];
    // how to create a array pointer for arr2? Ans:
    char *(*p4)[4] = &arr2; // char* means the target of this pointer is char pointer, *p4 means p4 is a pointer, [4] means arr2 has 4 element.
    // but we can see that in 1-D array, array pointer is not very useful, next part will explain where it been used usually

    /*******************************************************************************************************************/

    // if we have an array like this:
    int example[10];
    int* pt = example;
    // now example[i] == *(pt + i) == *(example + i) == pt[i]
    
    /*******************************************************************************************************************/


    // now we try to use simple method print all of element in 2-D array.
    void print1(int arr[3][5], int x, int y)
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }

    int test_arr[3][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    print1(test_arr, 3, 5);
    // then we know that except this two case(sizeof and get address), name of array means the address of first element
    // so test_arr is address of {1,2,3,4,5}
    // then we can rewrite the function :
    void print2(int(*p)[5], int x, int y)
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                printf("%d ", *(*(p + i) + j));
                // this part is very important for us to understand array pointer
                // first we know the parameter in this function int (*p)[5] means test_arr is a pointer target to a int array,
                // which have 5 element.

                // then (p+i) means the address of which row,
                // so *(p+i) is the first element's address of the row we choose, also the name of this 1-D array

                // *(p+i)+j means the address of which column of the row
                // finally, *(*(p+i)+j) is the int element we want to print.
            }
            printf("\n");
        }
    }
    print2(test_arr, 3, 5);

    /*******************************************************************************************************************/
    return 0;
}
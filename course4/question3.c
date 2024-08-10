#include <stdio.h>

/* 劍指offer */
// 題目:楊氏矩陣
// 介紹:存在一數字矩陣，規則為由上至下 由左至右遞增，但不一定連續。
// 要求:編寫程式判斷輸入是否存在於此矩陣中，且時間複雜度 < O(N)。
// 代表無法使用窮舉。

int check_in_array(int (*arr)[4], int size, int target)
{
    int exit_check = 0;
    int delete_row = 0;
    int delete_col = 0;
    
    do{
        int (*first_row)[4] = arr + delete_row;
        printf("%d\n",(*first_row)[3-delete_col]);
        if ((*first_row)[3-delete_col] == target)
        {
            exit_check = 1;
            break;
        }
        else if ((*first_row)[3-delete_col] > target)
        {
            delete_col++;
        }
        else{
            delete_row++;
        }
    }while((3-delete_col)>=0 | (size-delete_row) != 0);

    return exit_check;
}

int main()
{
    int target_array[4][4] = {{1, 2, 4, 5}, {2, 3, 6, 7}, {5, 6, 7, 8}, {6, 7, 8, 9}};
    int user_input;
    printf("please input an integer from 1-10\n> ");
    scanf("%d", &user_input);
    int answer = check_in_array(target_array,sizeof(target_array)/sizeof(target_array[0]),user_input);
    if (answer == 1){printf("your input is exist in the array");}
    else
    {
        printf("your input isn't exist in the array");
    }
    
    
    return 0;
}
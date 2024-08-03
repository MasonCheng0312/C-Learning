#include <stdio.h>

// char* mystr_cp(char* input){
//     return input;
// } // example
int Add(int x, int y)
{
    return x + y;
}

int Sub(int x, int y)
{
    return x - y;
}

int Mul(int x, int y)
{
    return x * y;
}

int Div(int x, int y)
{
    return x / y;
}
void menu()
{
    printf("*********Menu*******\n");
    printf("*1. Add       2.Sub*\n");
    printf("*3. Mul       4.Div*\n");
    printf("********0.exit******\n");
    printf("********************\n");
}
int choose_func()
{
    int function_mode;
    printf("choose the function!\n> ");
    scanf("%d", &function_mode);
    return function_mode;
}

void get_user_input(int *a, int *b)
{
    printf("please input two integer\n> ");
    scanf("%d%d", &(*a), &(*b));
}
int main()
{

    // practice for last course
    // try to create function pointer for mystr_cp
    // char* (*pt_func)(char*) = mystr_cp;
    // try to create a function pointer array
    // char* (*pt_arr[4])(char*) = {mystr_cp,mystr_cp,mystr_cp,mystr_cp};

    // use function pointer array to achieve simple computer
    // we can use swich to do this, but it is hard to add new function and read
    int (*p_function[])(int, int) = {0, Add, Sub, Mul, Div};
    int a = 1, b = 1;
    int check = 1;
    do
    {
        int num_of_func = sizeof(p_function) / sizeof(p_function[0]);
        menu();
        int mode = choose_func();

        if (mode != 0 && mode <= num_of_func)
        {
            get_user_input(&a, &b);
            printf("answer is : %d\n", p_function[mode](a, b));
        }
        else if (mode == 0)
        {
            check = 0;
            printf("thanks for your use\n");
        }
    } while (check);

    return 0;
}
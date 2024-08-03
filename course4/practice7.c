#include <stdlib.h> // qsort() is in this lib
#include <stdio.h>

struct student
{
    char name[20];
    char id[10];
    int age;
};

int cmp_float(const void *a, const void *b)
{
    return (int)(*(float *)a - *(float *)b);
}

int cmp_struct(const void *a, const void *b)
{   
    return ((struct student *)a)->age - ((struct student *)b)->age;
    // if we want to compare str type, use strcmp()
    // return strcmp(((struct student *)a)->name, ((struct student *)b)->name);
}

int main()
{
    // as we practice in last course, bubble sort can only sort element which is integer type
    // but if we want to sort something not integer?
    float f_arr[5] = {0.2, 0.1, 0.4, 0.6, 0.3};
    struct student Stu[3] = {{"kelly", "N00001", 15}, {"mason", "N00002", 13}, {"kan", "N00004", 18}};
    /* Important */
    // void* is a pointer with void type, it can accept parameter with any type
    // it sounds convenient for us to use, but it also has some restrict

    // in qsort(), the forth argument need a comparison function with integer return type and two void pointer input argument
    /* return value :
                >0 means a > b,
                =0 means a = b,
                <0 means a < b*/
    qsort(f_arr, sizeof(f_arr) / sizeof(f_arr[0]), sizeof(f_arr[0]), cmp_float);

    qsort(Stu, sizeof(Stu) / sizeof(Stu[0]), sizeof(Stu[0]), cmp_struct);

    return 0;
}
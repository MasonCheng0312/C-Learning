#include <stdio.h>

struct student
{
    char name[20];
    char id[10];
    int age;
};

void Swap(char *e1, char *e2, int ele_size)
{
    // swap element one by one byte
    for (int i = 0; i < ele_size; i++)
    {
        char tmp = *e1;
        *e1 = *e2;
        *e2 = tmp;
        e1++;
        e2++;
    }
}

void bubbleSort(void *p_Arr, int size_of_arr, int size_of_element, int (*p_cmp)(const void *, const void *))
{
    for (int i = 0; i < size_of_arr -1; i++)
    {
        for (int j = 0; j < size_of_arr - 1 - i; j++)
        {
            // consider that why we change pointer type from void to char
            // because char type only occupy 1 byte, so when we do some address process, it will only move 1 byte every time
            // same reason in Swap()             
            if (p_cmp((char *)p_Arr + (j * size_of_element), (char *)p_Arr + ((j + 1) * size_of_element)) > 0)
            {
                Swap((char *)p_Arr + (j * size_of_element), (char *)p_Arr + ((j + 1) * size_of_element),size_of_element);
            }
        }
    }
}

int cmp(const void * a, const void * b){
    return ((struct student *)a)->age - ((struct student *)b)->age;
}

int main()
{
    // expand bubble sort method to any type input
    struct student Stu[3] = {{"kelly", "N00001", 15}, {"mason", "N00002", 13}, {"kan", "N00004", 18}};
    // as usual, we have to pass array address to function
    // then because we don't know the space of element, so we have to pass how big it is to the function
    // also, size of array is an important info for function to complete sort
    // finally, the function must know the method to compare data in this array

    // (at here, we assume that user who use this bubble sort know his data type and know how to compare them)
    for (int i = 0; i < 3; i++) {
        printf("Name: %s, ID: %s, Age: %d\n", Stu[i].name, Stu[i].id, Stu[i].age);
    }

    bubbleSort(Stu,sizeof(Stu)/sizeof(Stu[0]),sizeof(Stu[0]),cmp);

    for (int i = 0; i < 3; i++) {
        printf("Name: %s, ID: %s, Age: %d\n", Stu[i].name, Stu[i].id, Stu[i].age);
    }
    return 0;
}
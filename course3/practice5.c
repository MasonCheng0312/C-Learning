#include <stdio.h>

struct student
{
    char name[20];
    int age;
    char id[10];
};


int main(){
    struct student kelly = {"kelly",18,"S00001"};
    printf("name of student is %s\n", kelly.name);
    // there is another way to call its member in struct with its pointer
    struct student* pt = &kelly;
    printf("name of student is %s\n", (*pt).name);
    // or use operator ->
    printf("name of student is %s\n", pt -> name);
    return 0;
}
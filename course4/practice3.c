#include <stdio.h>

// pass parameter or address to function.
void oneDirection_form1(int arr[10]){
    // pass whole array to function.
}

void oneDirection_form2(int arr[]){
    // pass whole array to function.
}

void oneDirection_form3(int* arr){
    // pass pointer to function.
}

void oneDirection_form4(int* arr[10]){
    // pass whole array to function.
}

void oneDirection_form5(int **arr){
    // pass pointer to function, and array' s element is int* type.
}

int main(){
    int arr[10] = {0};
    // these 3 form are all legal.
    oneDirection_form1(arr);
    oneDirection_form2(arr);
    oneDirection_form3(arr);

    // these 2 form are all legal.
    int* arr2[10];
    oneDirection_form4(arr2);
    oneDirection_form5(arr2);
    return 0;
}
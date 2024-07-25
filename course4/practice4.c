#include <stdio.h>

// pass parameter or address to function.
void twoDirection_form1(int arr[3][5]){
    // pass whole array to function.
}


void twoDirection_form3(int arr[][5]){

}
// void twoDirection_form2(int arr[][]){
// }

// void twoDirection_form4(int arr[3][]){   
// }

// these two form is illegal, in 2D array we can't omit column, because we must know how big the first element is.

// twoDirection_form5(int *arr){

// }
// be careful! this form is illegal because in 2D array, first element of array is also an array, we can't just use int* to catch it.

// twoDirection_form6(int **arr){

// }
// int** also wrong! int** means address of int*, not address of array.

void twoDirection_form7(int (*arr)[5]){}

int main(){
    int arr[3][5] = {0};
    twoDirection_form1(arr);
    // twoDirection_form2(arr);
    twoDirection_form3(arr);
    // twoDirection_form4(arr);

    // but if we want to pass pointer?
    // twoDirection_form5(arr);
    // twoDirection_form6(arr);
    twoDirection_form7(arr);

    
    return 0;
}
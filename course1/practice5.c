#include <stdio.h>

//practice binary search method
int findIndex(int target, int arr[], int size){
    // int size = sizeof(arr)/sizeof(arr[0]);
    //使用function時，傳入array作為參數會有退化(decay)的現象，標準作法是需要傳大小及array。

    int current_value = 0;
    int current_index = size/2;
    int min_index = 0;
    int max_index = size;
    while(current_value != target){
        current_value = arr[current_index];
        if (arr[current_index]>target)
        {
            max_index = current_index;
        }
        else if(arr[current_index]<target){
            min_index = current_index;
        }
        else{break;}
        current_index = (min_index + max_index)/2;
    }
    return current_index;
    
}

int main(){
    int target = 0;
    int arr[10] = {0};
    for(int i = 0; i<10; i++){
        arr[i] = i+1;
    }
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("please input a number between 1-10: \n");
    scanf("%d",&target);
    
    int ans = findIndex(target,arr,size);
    printf("index = %d",ans);
    return 0;
}
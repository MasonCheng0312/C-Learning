#include <stdio.h>

int main(){
    int k = 0;
    int i = 0;
    for(i = 0,k = 0; k = 0; i++, k++){
        printf("%d",k);
        k++;
    }
    return 0;
    // how many rounds does this loop run?(or how many times would this loop print k?)
    // Ans : 0 time.
    // because at condition part of for-loop is "k = 0", this expression will return bool value false.
}
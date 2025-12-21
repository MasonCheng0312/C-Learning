// Leetcode 11: find maximum container area
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    int* left_col = height;
    int* right_col = height + heightSize - 1;
    int max_area = 0;
    int weight = heightSize - 1;
    while (left_col < right_col)
    {
        int height = MIN(*left_col, *right_col);
        max_area = MAX((weight * height), max_area);

        if(*(left_col) < *(right_col)){
            left_col++;
            weight--;
        }
        else{
            right_col--;
            weight--;
        }
    }
    return max_area;
}
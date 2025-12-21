// Leetcode 88 : merge sorted array


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int* end_place = nums1 + m + n - 1;
    while(n){      
        if (m == 0 || (*(nums2 + n - 1) > *(nums1 + m - 1))){
            *end_place = *(nums2 + n - 1);
            n--;
        }
        else{
            *end_place = *(nums1 + m - 1);
            m--;
        }        
        end_place--; 
    }
}
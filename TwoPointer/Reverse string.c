void reverseString(char* s, int sSize) {
    char *left = s;
    char *right = s + sSize - 1;
    while( left < right ){
        char temp = *left;
        *left = *right;
        *right = temp;
        ++left;
        --right;
    }
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    for(int i=0; i < nums2Size; i++){
        int j=0;
        while( nums2[i] > nums1[j] && j < m ){
            ++j;
        }
        for(int t=m-1; t >= j; t--){
            nums1[t+1] = nums1[t];
        }
        nums1[j] = nums2[i];
        m++;
    }
}

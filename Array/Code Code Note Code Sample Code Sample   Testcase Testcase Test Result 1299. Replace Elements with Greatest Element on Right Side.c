/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int max(int a, int b)
{
    return ( a > b ) ? a : b;
}
int* replaceElements(int* arr, int arrSize, int* returnSize) {
    int *return_arr = (int*)malloc(arrSize * sizeof(arr[0]));
    if ( !return_arr ) return NULL;

    for(int i = arrSize - 2 ; i >= 0 ; i--)
    {
        arr[i] = max(arr[i], arr[i+1]);
        return_arr[i] = arr[i+1];
    }

    return_arr[arrSize - 1] = -1;
    *returnSize = arrSize;
    return return_arr;
    
}

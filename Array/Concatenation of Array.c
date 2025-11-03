//1929. Concatenation of Array
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int *return_arr = (int*)malloc( numsSize * sizeof(nums[0]) * 2 );
    if ( !return_arr ) return NULL;

    int i = 0;
    int j = 0;

    while( i < numsSize * 2 )
    {
        if ( i == numsSize ) j = 0;
        return_arr[i++] = nums[j++];
    }
     
    *returnSize = numsSize * 2;
    return return_arr;

}

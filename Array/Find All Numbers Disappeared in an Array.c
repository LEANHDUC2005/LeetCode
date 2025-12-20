/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    //int y = 0;
    for(int i=0; i<numsSize; i++)
    {
        // y = abs(nums[i]) - 1
        if ( nums[abs(nums[i]) - 1] > 0 ) nums[abs(nums[i]) - 1] = - nums[abs(nums[i]) - 1];
    }

    int j = 0;
    int *return_arr = (int*)malloc(sizeof(int) * numsSize);
    
    for(int i=0; i<numsSize; i++)
    {
        if ( nums[i] > 0 ) 
        {
            return_arr[j++] = i + 1;
        }
    }

    *returnSize = j;
    return return_arr;
}
// Hashing 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int hash[numsSize + 1];
    memset(hash , 0, sizeof(hash));
    for(int i=0; i < numsSize; i++){
        hash[nums[i]]++;
    }
    int *returnArr = (int*)malloc(numsSize * sizeof(int));
    int count = 0;
    for(int i=1; i < numsSize + 1; i++){
        if ( !hash[i] ) 
        returnArr[count++] = i;
    }
    *returnSize = count;
    return returnArr;
}

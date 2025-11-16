int pivotIndex(int* nums, int numsSize) {
    int sum = 0;
    int sumleft = 0;

    for(int i=0; i<numsSize; i++)
    {
        sum+= nums[i];
    }

    for(int i=0; i<numsSize; i++)
    {
        if ( sumleft == sum - ( sumleft + nums[i] ) ) return i;
        sumleft+= nums[i];
    }
    return -1;
}

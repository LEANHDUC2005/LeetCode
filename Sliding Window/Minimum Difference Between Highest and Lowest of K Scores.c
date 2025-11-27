void merge(int* nums, int left, int right, int mid)
{
    int L = mid - left + 1;
    int R = right - mid;

    int l[L];
    int r[R];
    for(int i=0; i < L; i++)
    {
        l[i] = nums[left + i];
    }
    for(int i=0; i < R; i++)
    {
        r[i] = nums[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while( i < L &&  j < R )
    {
        nums[k++] = ( l[i] <= r[j] ) ? l[i++] : r[j++];
    }
    while( i < L )
    {
        nums[k++] = l[i++];
    }
    while( j < R )
    {
        nums[k++] = r[j++];
    }
    
}
void mergeSort(int* nums, int left, int right)
{
    if ( left < right )
    {
        int mid = left + ( right - left ) / 2 ;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, right, mid);
    }
}
int minimumDifference(int* nums, int numsSize, int k) {
    mergeSort(nums, 0, numsSize - 1);
    int left = 0;
    int right = left + k - 1;
    int min = nums[right] - nums[left];

    while( left < right && right < numsSize )
    {
        if ( min > nums[right] - nums[left] )
        min = nums[right] - nums[left];
        right++;
        left++;
    }
    return min;
}

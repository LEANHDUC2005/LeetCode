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
// Counting Sort
void countingSort(int* nums, int numsSize)
{
    int max = 0;
    for(int i=0; i<numsSize; i++)
    {
        if ( nums[i] > max ) max = nums[i];
    }
    int count[max + 1];
    memset(count, 0, sizeof(count));
    int output[numsSize];

    for(int i=0; i<numsSize; i++)
    {
        count[nums[i]]++;
    }
    for(int i=1; i<max+1; i++)
    {
        count[i] += count[i - 1];
    }
    for(int i=numsSize-1; i>=0; i--)
    {
        output[count[nums[i]] - 1] = nums[i];
        count[nums[i]]--;
    }
    for(int i=0; i<numsSize; i++)
    {
        nums[i] = output[i];
    }
}
int minimumDifference(int* nums, int numsSize, int k) {
    countingSort(nums, numsSize);
    int *left = nums;
    int *right = nums + k - 1;
    int diff = *right - *left;
    int min = diff;

    while( left < right && right < nums + numsSize )
    {
        diff = *right - *left;
        if ( min > diff )
        min = diff;
        right++;
        left++;
    }
    return min;
}

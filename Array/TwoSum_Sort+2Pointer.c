/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void merge(int arr[], int l, int m , int r)
{
    int k,i,j;
    int n1 = l - m + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while( i < n1 && j < n2 )
    {
        if ( L[i] <= R[j] )
        {
            arr[k] = L[i];
            i++;
        }

        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while( i < n1 )
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while( j < n2 )
    {
        arr[k] = R[j];
        j++;
        k++;
    }

}
void mergesort(int arr[], int left, int right)
{

    if ( left < right )
    {
        int mid = (right - left + 1)/2 ;

        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int n = numsSize - 1;

    returnSize = (int*)(2 * sizeof(int));

    mergesort(nums, 0, n);

    int left, right, sum;
    left = 0;
    right = n;

    while ( left < right )
    {
        sum = nums[left] + nums[right];

        if ( sum == target )
        {
            returnSize[0] = left;
            returnSize[1] = right;
        }

        else if ( sum > target )
            right--;

        else 
            left++;
    }
    return returnSize;

}
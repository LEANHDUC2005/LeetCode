int binarySearchIndex(int* nums, int left, int right, int target){
    if ( left <= right ){
        int mid = left + ( right - left )/2;
        if ( target < nums[mid] ) return binarySearchIndex(nums, left, mid-1, target);
        if ( target > nums[mid] ) return binarySearchIndex(nums, mid+1, right, target);
        else return mid;
    }
    return left;
}
int searchInsert(int* nums, int numsSize, int target) {
    return binarySearchIndex(nums, 0, numsSize - 1, target);
}
int removeDuplicates(int* nums, int numsSize) {
    int slow = 0;
    for(int fast = 0; fast < numsSize; fast++){
        if ( nums[slow] != nums[fast])
        nums[++slow] = nums[fast];
    }
    return ++slow;
}

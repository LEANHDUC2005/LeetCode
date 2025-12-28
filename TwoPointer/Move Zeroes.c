void moveZeroes(int* nums, int numsSize) {
    int slow, fast;
    slow = fast = 0;
    for(fast; fast < numsSize; fast++){
        if ( nums[fast] != 0 ){
            int temp = nums[fast];
            nums[fast] = nums[slow];
            nums[slow++] = temp;
        }
    }
}

int removeElement(int* nums, int numsSize, int val) {
    int fast = numsSize - 1;
    int slow = numsSize - 1;

    for( fast; fast >=0; fast-- )
    {
        if ( nums[fast] == val )
        {
            int temp = nums[fast];
            nums[fast] = nums[slow];
            nums[slow] = temp;
            slow--;
        }
    }
    return slow + 1;

}

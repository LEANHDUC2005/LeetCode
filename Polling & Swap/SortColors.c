/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.


Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
*/
// Polling and Double Swapping
void swap(int* nums, int a, int b)
{
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}
void sortColors(int* nums, int numsSize) {
    int check = 0;
    int act_2 = 0;
    int act_1 = 0;
    for( check ; check < numsSize; check++ )
    {
        if ( nums[check] != 2 )
        {
            swap( nums , act_2, check );
            if ( nums[act_2] != 1 && nums[act_2] != 2 )
            {
                swap( nums, act_1, act_2 );
                act_1++;
            }
            act_2++;
        }
    }   
}
// Boyer–Moore majority vote algorithm
int majorityElement(int* nums, int numsSize) {
    int candidate = nums[0];
    int count = 0;
    for(int i=0; i < numsSize; i++)
    {
        if ( candidate == nums[i] ) count++;
        else count--;
        if ( count == 0 )
        {
            candidate = nums[i];
            count = 1;
        } 
    }
    return candidate;
}
// Bit Manipulation

int majorityElement(int* nums, int numsSize) {
    int count_bit[32];
    unsigned int result = 0;
    for(int i=0; i < 32; i++)
    {
        count_bit[i] = 0;
        for(int j=0; j<numsSize; j++)
        {
            if ( nums[j] >> i & 1 )
            {
                count_bit[i]++;
            }
        }
        if ( count_bit[i] > numsSize / 2)
        {
            result |= ( (unsigned int) 1 << i );
        }
    }
    return (int)result;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int prefix_product[numsSize];
    prefix_product[0] = nums[0];

    // Prefix 
    for(int i=1; i < numsSize; i++){
        prefix_product[i] = prefix_product[i - 1] * nums[i];
    }

    // Suffix
    int suffix_product[numsSize];
    suffix_product[numsSize - 1] = nums[numsSize - 1];

    for(int i=numsSize - 2; i >= 0; i--){
        suffix_product[i] = suffix_product[i + 1] * nums[i];
    }

    // Caculate
    for(int i=0; i < numsSize; i++){
        if ( i - 1 < 0 ){
            nums[i] = suffix_product[i + 1];
        }
        else if ( i + 1 >= numsSize ){
            nums[i] = prefix_product[i - 1];
        }
        else 
            nums[i] = prefix_product[i - 1] * suffix_product[i + 1];
    }

    // Result
    *returnSize = numsSize;
    return nums;
}
// Example
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    // 1. Initialize result array
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    // 2. First Pass: Left (Prefix) Products
    // result[i] will store the product of all elements to the left of index i
    int leftProduct = 1;
    for (int i = 0; i < numsSize; i++) {
        result[i] = leftProduct;
        leftProduct *= nums[i];
    }
    
    // 3. Second Pass: Right (Suffix) Products
    // Multiply the existing result[i] by the product of all elements to the right
    int rightProduct = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }
    
    return result;
}

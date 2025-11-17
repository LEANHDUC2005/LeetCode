
typedef struct {
    int *num;
    int *prefix;
    int size_nums;
    int size_prefix;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *obj = (NumArray*)malloc(sizeof(NumArray));

    obj->num = nums;
    obj->prefix = (int*)malloc(sizeof(int) * ( numsSize  + 1 ));
    if ( !obj->num || !obj->prefix ) perror("Error!");

    obj->size_nums = numsSize;
    obj->size_prefix = numsSize + 1;
    obj->prefix[0] = 0;

    for(int i=1; i<=numsSize; i++)
    {
        obj->prefix[i] = obj->prefix[i-1] + obj->num[i-1];
    }
    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->prefix[right] - obj->prefix[left] + obj->num[right];
}

void numArrayFree(NumArray* obj) {
    free(obj->num);
    free(obj->prefix);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/

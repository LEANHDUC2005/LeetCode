/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Hashing counting + Counting Sort
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int offset = 10000;
    int hashSize = 10000 + offset + 2;
    int hash[hashSize];
    memset(hash, 0, sizeof(hash));
    int max = 0;
    for(int i=0; i < numsSize; i++){
        hash[nums[i] + offset]++;
        if ( hash[nums[i] + offset] > max ){
            max = hash[nums[i] + offset];
        }
    }
    int count[max + 1];
    memset(count, 0, sizeof(count));
    for(int i=0; i < hashSize; i++){
        count[hash[i]]++;
    }
    for(int i=1; i < max + 1; i++){
        count[i] += count[i-1];
    }
    int outputSize = count[max];
    int *output = (int*)malloc(outputSize * sizeof(int));
    if ( !output ) return NULL;
    for(int i=hashSize - 1; i >= 0; i--){
        int k = hash[i];
        output[count[k] - 1] = i - offset;
        count[k]--;
    }
    int *returnArr = (int*)malloc(k * sizeof(int));
    if ( !returnArr ) return NULL;
    for(int i=0; i < k; i++){
        returnArr[i] = output[outputSize - 1 - i];
    }
    *returnSize = k;
    free(output);
    return returnArr;
}

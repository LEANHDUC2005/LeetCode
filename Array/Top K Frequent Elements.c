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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Struct + Remove Duplicate + Quick Sort
struct P{
    int num;
    int freq;
};

int cmp(const void *a, const void *b){
    return ((struct P*)b)->freq - ((struct P*)a)->freq;
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    struct P count[20001] = {0};
    int unique = 0;
    for(int i=0; i < numsSize; i++){
        int idx = nums[i] + 10000;
        if ( count[idx].freq == 0 ){
            count[idx].num = nums[i];
            count[idx].freq++;
        }
        count[idx].freq++;
    }
    
    struct P *uniqueArr = (struct P*)malloc(numsSize * sizeof(struct P));
    if ( !uniqueArr ) return NULL;
    for(int i=0; i < 20001; i++){
        if ( count[i].freq > 0 ){
            uniqueArr[unique++] = count[i];
        }
    }
    qsort(uniqueArr, unique, sizeof(struct P), cmp);
    int *returnArr = (int*)malloc(k * sizeof(int));
    for(int i=0; i < k; i++){
        returnArr[i] = uniqueArr[i].num;
    }
    *returnSize = k;
    free(uniqueArr);
    return returnArr;
}

int numOfSubarrays(int* arr, int arrSize, int k, int threshold) {
    int left = 0;
    int sum = 0;
    int count = 0;

    for(int i=0; i<k; i++)
    {
        sum += arr[i];
    }
    count = ( ( sum / k ) >= threshold );
    
    int right = k;
    for(right; right<arrSize; right++)
    {
        sum += arr[right];
        sum -= arr[left];
        left++;
        if (  ( sum / k ) >= threshold ) count++;
    }
    return count;
}

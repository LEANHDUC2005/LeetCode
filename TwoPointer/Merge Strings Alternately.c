char* mergeAlternately(char* word1, char* word2){
    int high = ( strlen(word1) > strlen(word2) ? strlen(word1) : strlen(word2) );
    int low = ( strlen(word1) < strlen(word2) ? strlen(word1) : strlen(word2) );
    int resultSize = high + low;
    printf("high: %d | low: %d\n", high, low);
    printf("%d\n", resultSize);
    char *result = (char*)malloc(resultSize + 1);
    int one = -2;
    int two = -1;
    for(int i=0; i < low; i++){
        one+= 2;
        two+= 2;
        result[one] = word1[i];
        result[two] = word2[i];
    }
    printf("one: %d | two: %d\n", one, two);
    for(int i= low; i < high; i++){
        if ( high == strlen(word1)){
            result[++two] = word1[i];
        }
        else{
            result[++two] = word2[i];
        }
    }
    result[resultSize] = '\0';
    return result;
}
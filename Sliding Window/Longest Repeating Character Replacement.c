int characterReplacement(char* s, int k) {
    int hash[91];
    memset(hash, 0 , sizeof(hash));

    char *left = s;
    char *right = s;

    int length = 0;
    int max_count = 0;
    int max_length = 0;

    while( *right != '\0' )
    {
        hash[(*right)]++;
        if ( max_count < hash[(*right)] )  max_count = hash[(*right)];
        while( right - left + 1 - max_count > k ) 
        {
            hash[(*left)]--;
            left++;
        }
        length = right - left + 1;
        if ( max_length < length )
            max_length = length;
        right++;
    }
    return max_length;
}


int lengthOfLongestSubstring(char* s) {

    int hash[256];
    memset(hash, -1, sizeof(hash));

    int max_length = 0;
    int length = 0;
    char *left = s;
    char *right = s;

    while( *right != '\0' )
    {
        while ( left < right && hash[(*right)] != -1 )
        {
            length = right - left;
            if ( length > max_length ) 
                max_length = length;
            hash[(*left)] = -1;
            left++;
        }

        hash[(*right)] = (int)right;
        right++;
    }


    length = right - left;
    if ( length > max_length ) 
        max_length = length;

    return max_length;
}
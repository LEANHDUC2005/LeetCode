void reverseString(char* s, int sSize) {
    char *left = s;
    char *right = s + sSize - 1;
    while( left < right ){
        char temp = *left;
        *left = *right;
        *right = temp;
        ++left;
        --right;
    }
}

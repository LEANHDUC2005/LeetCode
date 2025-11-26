bool TwoWayShift(char *left, char *right)
{
    while( left < right )
    {
        if ( *left != *right ) return false;
        left++;
        right--;
    }
    return true;
}
bool validPalindrome(char* s) {
    char *left = s;
    char *right = s + strlen(s) - 1;
    while( left < right )
    {
        if ( *left != *right )
        return ( TwoWayShift(left + 1, right) || TwoWayShift(left, right - 1) );
        left++;
        right--;
    }
    return true;
}

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        int flag = 0;

        while( left < right )
        {
            if ( s[left] != s[right] )
            {
                if ( !flag )
                {
                    flag = 1;
                    left++;
                    continue;
                } 
                else
                {
                    flag = 0;
                    break;
                }  
            }
            left++;
            right--;
        }

        if ( flag ) return true;
        left = 0;
        right = s.size() - 1;

        while( left < right )
        {
            if ( s[left] != s[right] )
            {
                if ( !flag )
                {
                    flag = 1;
                    right--;
                    continue;
                }
                else
                {
                    return false;
                }
            }
            left++;
            right--;
        }
        return true;
    }
};

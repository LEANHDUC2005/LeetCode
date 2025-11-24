class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(91);
        int left = 0;
        int right = 0;

        int max_count = 0;
        int max_length = 0;
        int length = 0;
        for(right ; right<s.size(); right++)
        {
            hash[s[right]]++;
            if ( max_count < hash[s[right]] ) 
                max_count = hash[s[right]];

            while( right - left + 1 - max_count > k )
            {
                hash[s[left]]--;
                left++;
            }

            length = right - left + 1;
            if ( max_length < length ) 
                max_length = length;
        }
        return max_length;
    }
};
// Sliding Window
// 1. Left = Right = 0;
// 2. Move Right until end the string
// 3. If Length of window - Count of the most Rapeating Character > k 
// - Close the window
// - Find C.O.T.M.R.C each time we close the window
// Tricky Tips:
// Use Condition: Length Window - Max Count > k
// Max Count = max(hash[s[right]], Max Count)

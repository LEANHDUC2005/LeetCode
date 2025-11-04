class Solution {
public:
    void remove_space_2_side(string &s)
    {
        int start;
        int end;

        for(start=0; isspace(s[start]) ; start++);
        for(end=s.size()-1; isspace(s[end]) ; end--);

        s = s.substr(start,end - start + 1);
    }
    int lengthOfLastWord(string s) {
        int space = -1;
        remove_space_2_side(s);
        cout << "[" << s << "]";

        for(int i=0; i<s.size(); i++)
        {
            if ( isspace(s[i]) ) space = i;
        }

        return s.size() - ( space + 1 );
    }
};

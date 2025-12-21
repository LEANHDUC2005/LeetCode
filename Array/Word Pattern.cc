using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> hash_ps;
        unordered_map<string, char> hash_sp;
        vector<string> s_word;
        string word;

        stringstream ss(s);
        while( ss >> word ){
            s_word.push_back(word);
        }
        
        if ( pattern.size() != s_word.size() ) return false;

        for(int i=0; i < pattern.size(); i++){
            if ( hash_ps.count(pattern[i]) && hash_ps[pattern[i]] != s_word[i] )
            return false;
            if ( hash_sp.count(s_word[i]) && hash_sp[s_word[i]] != pattern[i] )
            return false;
            hash_ps[pattern[i]] = s_word[i];
            hash_sp[s_word[i]] = pattern[i];
        }
        return true;
    }
};

bool isIsomorphic(char* s, char* t) {
    if ( s == NULL || t == NULL ) return false;
    if ( strlen(s) != strlen(t) ) return false;
    
    char s_hash[256];
    char t_hash[256];

    for(int i=0; i<256; i++)
    {
        s_hash[i] = t_hash[i] = -1;
    }
    for(int i=0; i<strlen(s); i++)
    {
        if ( s_hash[s[i]] == -1 && t_hash[t[i]] == -1 )
        {
            s_hash[s[i]] = t[i];
            t_hash[t[i]] = s[i];
        }
        else 
        {
            if ( s_hash[s[i]] != t[i] || t_hash[t[i]] != s[i] )
            return false;
        }
    }
    return true;
}

void makePrefix(char* prefix, char* str)
{
    int end = 0;
    for(end; ( prefix[end] == str[end] ) && ( end < strlen(prefix) ); end++);
    prefix[end] = '\0';
}
char* longestCommonPrefix(char** strs, int strsSize) {
    char* prefix = strs[0];
    for(int i=0; i < strsSize; i++)
    {
        makePrefix(prefix, strs[i]);
    }
    return prefix;
}

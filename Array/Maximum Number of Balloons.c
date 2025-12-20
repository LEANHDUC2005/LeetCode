int min(int a, int b){
    return ( a < b ) ? a : b;
}
int maxNumberOfBalloons(char* text) {
    int hash[256];
    memset(hash, 0 , sizeof(hash));
    for(int i=0; i < strlen(text); i++){
        hash[text[i]]++;
    }
    int b_count = hash['b'];
    int a_count = min(hash['a'], b_count);
    int l_count = min(hash['l']/2, a_count);
    int o_count = min(hash['o']/2, l_count);
    int n_count = min(hash['n'], o_count);
    return n_count;
}

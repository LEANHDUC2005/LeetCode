void HashSetAdd(int *table, char key){
    *table |= 1 << key ;
}

bool HashSetContain(int *table, char key){
    return (*table & ( 1 << key )) ;
}
bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int hash_row[10] = {0};
    int hash_col[10] = {0};
    int hash_box[3][3] = {0};
    for(int i=0; i < boardSize; i++){
        for(int j=0; j < *boardColSize; j++){
            if ( board[i][j] == '.') continue;
            int key = board[i][j] - '0';
            if ( !HashSetContain(&hash_row[i], key)
            && !HashSetContain(&hash_col[j], key)
            && !HashSetContain(&hash_box[i/3][j/3], key)){
                HashSetAdd(&hash_row[i], key);
                HashSetAdd(&hash_col[j], key);
                HashSetAdd(&hash_box[i/3][j/3], key);
            }
            else return false;
        }
    }
    return true;
}

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    for(int i=0; i < matrixColSize[0]; i++){
        int j = i;
        int start = 0;
        int val = matrix[start][j];
        while( start < matrixSize && j < matrixColSize[0] ){
            if ( matrix[start][j] != val ) return false;
            ++start;
            ++j;
        }
    }

    for(int i=1; i < matrixSize; i++){
        int j = i;
        int start = 0;
        int val = matrix[j][start];
        while( start < matrixColSize[0] && j < matrixSize ){
            if ( matrix[j][start] != val ) return false;
            ++start;
            ++j;
        }
    }
    return true;
}

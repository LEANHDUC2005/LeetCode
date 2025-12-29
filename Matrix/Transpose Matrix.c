/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int **new = (int**)malloc(matrixColSize[0] * sizeof(int*));
    if ( !new ) return NULL;
    *returnColumnSizes = (int*)malloc(matrixColSize[0] * sizeof(int));

    for(int i=0; i < matrixColSize[0]; i++){
        new[i] = (int*)malloc(matrixSize * sizeof(int));
        (*returnColumnSizes)[i] = matrixSize;
        if ( !new[i] ) return NULL;
    }
    
    // NEW[a][b] = MATRIX[b][a]
    for(int i=0; i < matrixColSize[0]; i++){
        for(int j=0; j < matrixSize; j++){
            new[i][j] = matrix[j][i];
        }
    }

    *returnSize = matrixColSize[0];
    return new;
}
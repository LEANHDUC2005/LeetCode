/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** returnColumn = (int**)malloc(numRows * sizeof(int*));
    int* returnColumnSize = (int*)malloc(numRows * sizeof(int));

    for(int i=0; i<numRows; i++)
    {
        returnColumnSize[i] = i+1;
        returnColumn[i] = (int*)malloc((i+1) * sizeof(int));
        returnColumn[i][0] = returnColumn[i][i] = 1;
        for(int j=1; j<i; j++)
        {
            returnColumn[i][j] = returnColumn[i-1][j-1] + returnColumn[i-1][j];
        }
    }
    *returnSize = numRows;
    *returnColumnSizes = returnColumnSize;
    return returnColumn;
}

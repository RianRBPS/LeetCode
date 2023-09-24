/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    
    // Se o numero de colunas for negativo
    if (numRows <= 0) {
        *returnSize = 0;
        return NULL;
    }
    
    // Alocando memoria para o triangulo
    int** triangle = (int**)malloc(sizeof(int*) * numRows);
    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);
    
    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        triangle[i] = (int*)malloc(sizeof(int) * (i + 1));
        triangle[i][0] = 1;  // O primeiro elemento sempre eh 1
        triangle[i][i] = 1;  // O ultimo elemento sempre eh 1

        // Preenchendo os elementos do meio
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    
     *returnSize = numRows;
    return triangle;

}


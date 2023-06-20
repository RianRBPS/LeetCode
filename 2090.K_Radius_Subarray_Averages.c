// Link do Problema
// https://leetcode.com/problems/k-radius-subarray-averages/
#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getAverages(int* nums, int numsSize, int k, int* returnSize){

    // Alocando a memoria p/ o array de retorno 
    int *retarr = malloc(numsSize * sizeof(int));

    // Preenchendo todas as posições do array com o valor -1
    for(int i=0; i<numsSize; i++){
        retarr[i] = -1;
    }

    
    int t, sum = 0;

    // Percorrendo o array numSize para encontrar as posições que atendam aos requisitos do enunciado
    for(int i=0; i<numsSize; i++){
        if(i-k >= 0 && i+k < numsSize){
            t = i - k;
            for(t; t<=i+k; t++){
                sum += nums[t];
            }
            retarr[i] = sum / (2*k + 1);
            sum = 0;
        }
    }

    *returnSize = numsSize;
    return retarr;
}

int main() {
    int tam;
    scanf("%d", &tam);

    int num[tam];
    for(int i=0; i<tam; i++){
        scanf("%d", &num[i]);
    }

    int k;
    scanf("%d", &k);

    int * numA;
    int tam2;
    numA = getAverages(num, tam, k, &tam2);

    for(int i=0; i<tam; i++){
        printf("%d", numA[i]);
    }
    

}
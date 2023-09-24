// Link do Problema
// https://leetcode.com/problems/k-radius-subarray-averages/
#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getAverages(int* nums, int numsSize, int k, int* returnSize){

    // Alocando a memoria p/ o array de retorno 
    // Pq colocar o (int*) antes do malloc?
    int *retarr = (int*)malloc(numsSize * sizeof(int));

    // Preenchendo todas as posições do array com o valor -1
    for(int i=0; i<numsSize; i++){
        retarr[i] = -1;
    }

    // Pq long e não int?
    long sum = 0;

    // Diametro gerado pelo raio k com centro no ponto i
    int lenght = 2 * k + 1;

    // Percorrendo o array numSize para encontrar as posições que atendam aos requisitos do enunciado
    for(int i=0; i<numsSize; i++){
        sum += nums[i];
        if(i+1>=lenght){
            retarr[i-k] = sum / lenght;
            sum -= nums[i + 1 - lenght];
        }

    }

    // Declarando o tamanho do array de retorno
    *returnSize = numsSize;
    return retarr;
}
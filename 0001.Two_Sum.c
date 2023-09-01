#include <stdio.h>
#include <stdlib.h>

// Solução 1

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum1(int* nums, int numsSize, int target, int* returnSize){
    
    // Alocando a memória necessária
    int *arrayRetorno = malloc(2 * sizeof(int));

    // Atribuindo um valor arbitrário para as posições 0 e 1 do array de retorno
    arrayRetorno[0] = 1;
    arrayRetorno[1] = 1;

    // Percorrendo o vetor numsSize para encontrar o primeiro caso em que a soma de dois elementos das posições do vetor retorne o elemento target
    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j < numsSize; j++){
            // Conferindo se as a soma das duas posições atuais do vetor retorna o target
            if (nums[i] + nums[j] == target){
                // Tanab
                *returnSize = 2; // Read #1
                arrayRetorno[0] = i;
                arrayRetorno[1] = j;
                return arrayRetorno;
            }
        }
    }

    *returnSize = 0; // Read #1
    return NULL;
}

/* 
#1
In C, when you return a dynamically allocated array, it has no idea how long your array is. Therefore, you need to also return the array’s size. That’s why there is a parameter returnSize passed in so that you can assign the array’s size to it.

To assign the array’s size, do this:

*returnSize = n;   // if the array's size is n.
*/


// Solução 2
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum2(int* nums, int numsSize, int target, int* returnSize){

    int* retarr = (int*)malloc(2*(sizeof(int)));
    *returnSize =2;

    int i = 0, j = 1;
    while(i<numsSize){

        if(j == numsSize){
            i++;
            j = i + 1;
        }

        if(nums[i] + nums[j] == target){
            break;
        }else{
            j++;
        }
    }

    retarr[0] = i;
    retarr[1] = j;

    return retarr;
}
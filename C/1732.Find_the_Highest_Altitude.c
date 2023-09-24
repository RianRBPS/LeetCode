// Link do Problema
//https://leetcode.com/problems/find-the-highest-altitude/

#include <stdio.h>
#include <stdlib.h>

// Number of points: n+1
// Start: point 0 && altitude 0
// Lenght: gain[n]


int largestAltitude(int* gain, int gainSize){
    
    // Alocando a memória para o array de altitudes
    int *retarr = malloc((gainSize + 1) * (sizeof(int)));

    // Primeira altitude
    retarr[0] = 0;

    // Preenchendo o array altitude com as variações de altitude do array gain
    for(int i = 1; i<(gainSize+1); i++){
        retarr[i] =retarr[i-1] + gain[i-1]; 
    }

    // Percorrendo o array de altitudes para encontrar a maior altitude 
    int maior = retarr[0];
    for(int i = 1; i<(gainSize+1); i++){
        if(retarr[i] > maior){
            maior = retarr[i];
        }
    }

    // Retornando o maior valor encontrado no array retarr
    return maior;
}
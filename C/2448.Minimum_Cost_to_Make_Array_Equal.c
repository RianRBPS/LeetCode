// Link do problema
// https://leetcode.com/problems/minimum-cost-to-make-array-equal/

//  Binary Search is defined as a searching algorithm used in a sorted array by repeatedly dividing the search interval in half. The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(log N). 
// Source:
// https://www.geeksforgeeks.org/binary-search/

//  A Sorting Algorithm is used to rearrange a given array or list of elements according to a comparison operator on the elements. The comparison operator is used to decide the new order of elements in the respective data structure.
// Source:
// https://www.geeksforgeeks.org/sorting-algorithms/

//  Merge sort is defined as a sorting algorithm that works by dividing an array into smaller subarrays, sorting each subarray, and then merging the sorted subarrays back together to form the final sorted array.
// Source:
//  https://www.geeksforgeeks.org/merge-sort/

long long getSoma(int* nums, int numSize, int* cost, int mid){
    long long soma = 0;
    for(int i=0; i<numSize; i++){
        // abs retorna o módulo
        long long k = abs(nums[i] - mid);
        soma +=k * cost[i];
    }
    return soma;
}

long long minCost(int* nums, int numsSize, int* cost, int costSize){
    // Pq maior = 1e6?
    long long menor = 1, maior = 1e6;
    while(menor<=maior){
        int meio = (menor + maior) / 2;
        long long soma1 = getSoma(nums, numsSize, cost, meio);
        if(menor == maior){
            return soma1;
        }
        long long soma2 = getSoma(nums, numsSize, cost, meio - 1);
        long long soma3 = getSoma(nums, numsSize, cost, meio + 1);

        if(soma2 >= soma1 && soma1 <= soma3){
            return soma1;
        }
        if(soma2 < soma1){
            maior = meio;
            // Pq continue?
            continue;
        }
        if(soma3 < soma1){
            menor = meio;
            // Pq continue?
            continue;
        }
    }
    return 0;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* countBits(int n, int* returnSize){

    int* ans = (int*)malloc(sizeof(int)*(n+1));
    *returnSize = n+1;
    int j = 0;

    for(int i = 0; i<= n; i++){
        ans[i] = 0;
        j = i;
        while(j != 0){
            if(j%2 == 1){
                j--;
                j = j/2;
                ans[i]++;
            }else{ // j%2 == 0
                j = j/2;
            }   
        }
    }

    return ans;

}
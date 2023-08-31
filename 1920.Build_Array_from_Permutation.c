int* buildArray(int* nums, int numsSize, int* returnSize){

    int *ans = (int*)malloc(numsSize * (sizeof(int)));

    // Cada elemento i de ans recebe o elemento da posição "nums[i]" de nums
    for(int i = 0; i < numsSize; i++){
        ans[i] = nums[nums[i]];
    }

    *returnSize = numsSize;
    return ans;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    
    int *retarr = (int*)malloc(2*(sizeof(int)));

    int first = -1;
    int last = first;

    for(int i = 0; i<numsSize; i++){
        if(nums[i] == target && first == -1){
            first = i;
            last = i;
        }else if(nums[i] == target){
            last = i;
        }
    }

    retarr[0] = first;
    retarr[1] = last;

    *returnSize = 2;
    return retarr;
}
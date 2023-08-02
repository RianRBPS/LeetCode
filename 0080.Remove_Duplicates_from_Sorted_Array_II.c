int removeDuplicates(int* nums, int numsSize){
    
    // Sempre que a posição j-2 for diferente da posição i
    // Fazer com que a posição j receba o valor da posição i

    int j = 2;
    if(numsSize == 1){
        return 1;
    }

    for(int i = 2; i < numsSize; i++){
        if(nums[j-2] != nums[i]){
            nums[j] = nums[i];
            j++;
        }
    }

    return j;
}

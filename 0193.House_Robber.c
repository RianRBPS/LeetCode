int max(int a, int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

int rob(int* nums, int numsSize){

    if(numsSize == 1){
        return nums[0];
    }else if(numsSize == 2){
        return max(nums[0], nums[1]);
    }


    for(int i = numsSize - 3; i>=0; i--){
        if(i == (numsSize - 3)){
            nums[i] += nums[i+2];
        }else{
            nums[i] += max(nums[i+2], nums[i+3]);
        }
    }

    return max(nums[0], nums[1]);
}
int searchInsert(int* nums, int numsSize, int target){

    if(nums[0] > target){
        return 0;
    }
    
    for(int i = 0; i<numsSize; i++){
        if(nums[i] == target){
            return i;
        }else if(i != 0){
            if(nums[i-1] < target && nums[i] > target){
                return i;
            }
        }
    }

    return numsSize;
} 
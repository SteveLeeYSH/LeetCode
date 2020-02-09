/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    for(int i = 0; i < numsSize; i++) {
        nums[i] = target - nums[i];
        for(int j = i + 1; j < numsSize; j++) {
            if(nums[i] == nums[j]) {
                int* buff = (int*)malloc(2 * sizeof(int));
                buff[0] = i;
                buff[1] = j;
                *returnSize = 2;
                return buff;
            }
        }
    }
    
    *returnSize = 0;
    return NULL;
}


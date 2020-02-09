/* raw version */
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

/* qsort & bsearch version */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct numInfo {
    int value;
    int index;
} numInfo;

int compare(const void* a, const void* b) {
    return ((numInfo*)a)->value - ((numInfo*)b)->value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    numInfo* infos = (numInfo*)malloc(numsSize * sizeof(numInfo));
    for(int i = 0; i < numsSize; i++) {
        infos[i].value = nums[i];
        infos[i].index = i;
    }
    qsort(infos, numsSize, sizeof(numInfo), compare);
    
    for(int i = 0; i < numsSize - 1; i++) {
        nums[i] = target - infos[i].value;
        if(infos[i + 1].value > nums[i]) {
            break;
        }
        if(infos[numsSize - 1].value < nums[i]) {
            continue;
        }
        
        numInfo* res = (numInfo*)bsearch(&(nums[i]), &(infos[i + 1]), numsSize - i - 1, sizeof(numInfo), compare);
        if(res != NULL) {
            int* buff = (int*)malloc(2 * sizeof(int));
            buff[0] = infos[i].index;
            buff[1] = res->index;
            *returnSize = 2;
            free(infos);
            return buff;
        }
    }
    
    free(infos);
    *returnSize = 0;
    return NULL;
}

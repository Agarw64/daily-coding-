#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2; 

    int* result = (int*)malloc(2*sizeof(int)); //Need to have the array of our two indices survive after function ends
    if (result == NULL) { //saftey check for memory allocation
        return NULL; 
    }

    for (int i = 0; i < numsSize; i++ ) {
        //second loop to ensure we dont compare numbers to the number being iterrated through by i 
        for(int j = i+1; j <numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result; 
            }
        }
    }

    return NULL; // should never have to reach here i think 
}

int main(void){
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int len = 4;
    int returnSize;

    int* indices = twoSum(nums, len, target, &returnSize);

    if (indices != NULL) {
        printf("Indices found: [%d, %d]\n", indices[0], indices[1]);

        free(indices);
    }
    else {
        printf("No solution found.\n");
    }

    return 0; 
}


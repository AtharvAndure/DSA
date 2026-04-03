// "Learn about Hashmap that they doesn't have any inbuilt O(1) insertion and deletion function"
#include<stdio.h>
#include<stdlib.h>
// for using bool data type in c
#include<stdbool.h>

struct Hashmap{
    int val;
    bool status;
};


bool containsDuplicate(int* nums, int numsSize) {
    // set alloc bit to 0 which make all struct=> val=00000 => 0 and status=00000 => false
    struct Hashmap * arr= (struct Hashmap *)calloc(numsSize+1,sizeof(struct Hashmap));

    for(int i=0;i<numsSize;i++){
        int index=((nums[i] % numsSize)+numsSize)%numsSize;
        
        // Use -> (Arrow): When your variable is a pointer to a struct.
        // Use . (Dot): When your variable is the actual struct value.
        while(arr[index].status==true){
            if(nums[i]==arr[index].val)
                return true;
            index=(index+1)%numsSize;
        }
        arr[index].val=nums[i];
        arr[index].status=true;
    }
    return false;
}

int main(){
    int arr[5] = {1,2,3};
    printf("Is it sunny? %s\n", containsDuplicate(arr,3) ? "true" : "false");
    return 0;
}
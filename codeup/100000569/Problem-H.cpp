#include <stdio.h>
int main(){
    int nums[10], i=0, j=1;
    for(i=0;i<10;i++)
        scanf("%d", &nums[i]);
    for(i=0;i<10;i++){
        for(j=1;j<10-i;j++){
            if(nums[j-1]>nums[j]){
                int temp = nums[j-1];
                nums[j-1]=nums[j];
                nums[j]=temp;
            }
        }
    }
    for(i=0;i<10;i++)
        printf("%d\n", nums[i]);
    return 0;
}

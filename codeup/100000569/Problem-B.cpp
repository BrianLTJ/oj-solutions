#include <stdio.h>
int main() {
    int i=0,nums[10]={0};
    for(i=0;i<10;i++) {
        scanf("%d",&nums[i]);
    }
    // Reverse
    for(i=0;i<5;i++){
        int temp = nums[i];
        nums[i]=nums[9-i];
        nums[9-i] = temp;
    }
    for(i=0;i<10;i++) {
        printf("%d\n",nums[i]);
    }
    return 0;
}

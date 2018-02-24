#include <stdio.h>
int main(){
    int nums[10]={0};
    int i=0;
    for(i=0;i<10;i++)
        scanf("%d", &nums[i]);
    for(i=9;i>=0;i--)
        printf("%d\n",nums[i]);
    return 0;
}

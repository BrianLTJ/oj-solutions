/*
 * http://www.codeup.cn/problem.php?cid=100000569&pid=0
 */

 #include <stdio.h>

 int main(){
    int nums[10]={0}, n=0, temp=0;
    for(int i=0;i<9;i++){
        scanf("%d", &nums[i]);
    }
    scanf("%d", &temp);
    for(n=0;n<9;n++) {
        if(temp<nums[n]) break;
    }
    //move
    for(int i=9;i>n;i--){
        nums[i]=nums[i-1];
    }
    nums[n]=temp;
    for(int i=0;i<10;i++){
        printf("%d\n", nums[i]);
    }
    return 0;
 }


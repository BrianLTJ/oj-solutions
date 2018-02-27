#include <stdio.h>
#include <algorithm>
void inputNums(int *n) {
    for(int i=0;i<10;i++)
        scanf("%d", (n+i));
}
void change(int *n){
    int maxid=0, minid=0;
    int maxnum = n[maxid], minnum=n[minid], temp;
    for(int i=1;i<10;i++){
        if(n[i]>maxnum){
            maxid=i;maxnum=n[i];
        }
        if(n[i]<minnum) {
            minid=i; minnum = n[i];
        }
    }
    //Exchange
    temp = n[0]; n[0]=minnum; n[minid]=temp;
    temp = n[9]; n[9]=maxnum; n[maxid]=temp;

}
void outputNums(int *n){
    for(int i=0;i<10;i++)
        printf("%d ", n[i]);
    printf("\n");
}
int main(){
    int nums[10]={0};
    inputNums(nums);
    change(nums);
    outputNums(nums);
    return 0;
}


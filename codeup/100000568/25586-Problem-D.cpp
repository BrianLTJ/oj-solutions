#include<stdio.h>
int main(){
    int i=1,sum=0,n=0;
    scanf("%d",&n);
    while(1){
        if(i>n) break;
        sum+=i;
        i++;
    }
    printf("%d\n", sum);
    return 0;
}

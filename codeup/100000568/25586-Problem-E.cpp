#include<stdio.h>
int main(){
    int i=1,sum=0,n=0;
    while(1){
        if(sum>1000) break;
        sum+=i;
        i++;
    }
    printf("%d\n", i-1);
    return 0;
}

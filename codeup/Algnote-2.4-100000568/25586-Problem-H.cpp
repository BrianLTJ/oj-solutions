#include<stdio.h>
int main(){
    int f1=1,f2=1,f3=f1+f2,n=0;
    scanf("%d", &n);
    for(int i=3;i<=n;i++){
        f3=f1+f2;
        f1=f2;
        f2=f3;
    }
    printf("%d\n",f2);
    return 0;
}

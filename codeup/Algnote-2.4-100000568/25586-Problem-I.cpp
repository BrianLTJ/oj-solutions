#include<stdio.h>
int main(){
    int n=20;
    double f1=1.0,f2=2.0,f3=f1+f2,sum=f2/f1;
    for(int i=2;i<=n;i++){
        f3=f1+f2;
        f1=f2;
        f2=f3;
        sum+=(f2/f1);
    }
    printf("%.6f\n",sum);
    return 0;
}

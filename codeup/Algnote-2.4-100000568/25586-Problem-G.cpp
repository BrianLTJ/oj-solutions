#include<stdio.h>
#include<cmath>
int main(){
    double sum=0.0,i=0.0;
    while(1) {
        double item = 1.0/(i*2+1);
        if(item >= pow(10.0,-6.0))
            sum+=(pow(-1.0,i)*item);
        else
            break;

        i=i+1.0;
    }
    printf("PI=%.8f",sum*4.0);
    return 0;
}

#include<stdio.h>
int main(){
    int a[10] = {7,9,4,12,2};
    for(int i = 1;i<=4;i++){
        for(int j=0;j<5-i;j++){
            if(a[j]>a[j+1]) {
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        // output
        for(int k = 0;k<5;k++)
            printf("%3d",a[k]);
        printf("\n");
    }
    return 0;
}

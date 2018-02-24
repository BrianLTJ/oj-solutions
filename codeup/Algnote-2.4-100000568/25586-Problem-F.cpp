#include<stdio.h>
int main(){
    int i=0;
    for(i=1;i<=4;i++){
        for(int j=1;j<=5;j++)
            printf("%3d",j*i);

        printf("\n");
    }
    return 0;
}

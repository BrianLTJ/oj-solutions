#include <stdio.h>
int main(){
    int n1=0,n2=1,n3;
    printf("%d\n",n2);
    for(int i=2;i<=20;i++){
        n3=n1+n2;
        n1=n2;
        n2=n3;
        printf("%d\n",n2);
    }
    return 0;
}

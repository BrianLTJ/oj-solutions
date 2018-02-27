#include <stdio.h>

int main(){
    int a, b;
    int *p1=&a, *p2=&b;
    scanf("%d", p1);
    scanf("%d", p2);
    if(*p1<*p2){
        printf("%d %d", *p2, *p1);
    }else {
        printf("%d %d", *p1, *p2);
    }
    return 0;
}

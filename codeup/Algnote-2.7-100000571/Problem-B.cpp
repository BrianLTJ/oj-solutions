#include <stdio.h>
int main(){
    int a, b, c;
    int *p1=&a, *p2=&b, *p3=&c;
    scanf("%d", p1);
    scanf("%d", p2);
    scanf("%d", p3);
    int cmp=0;
    cmp += (*p1>*p2)? 100:0;
    cmp += (*p2>*p3)? 10:0;
    cmp += (*p1>*p3)? 1:0;
    switch(cmp) {
        case 111:
            printf("%d %d %d", *p1, *p2, *p3);
            break;
        case 101:
            printf("%d %d %d", *p1, *p3, *p2);
            break;
        case 100:
            printf("%d %d %d", *p3, *p1, *p2);
            break;
        case 11:
            printf("%d %d %d", *p2, *p1, *p3);
            break;
        case 10:
            printf("%d %d %d", *p2, *p3, *p1);
            break;
        case 0:
            printf("%d %d %d", *p3, *p2, *p1);
            break;
    }
    return 0;
}

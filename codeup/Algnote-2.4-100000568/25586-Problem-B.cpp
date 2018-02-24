/*
 *http://codeup.hustoj.com/problem.php?cid=100000568&pid=4
*/
#include<stdio.h>
int main(){
    int i=0,sum=0;
    do{
        sum+=(++i);
    }while(i<100);
    printf("%d\n", sum);
    return 0;
}

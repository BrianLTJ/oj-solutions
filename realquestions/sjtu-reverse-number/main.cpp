#include <cstdio>

using namespace std;
int getReverse(int n){
    int temp = n;
    int revNum = 0;
    while(temp>0){
        revNum=revNum*10+temp%10;
        temp=temp/10;
    }
    return revNum;
}

int main()
{
    int n1=0,n2=0;
    while(scanf("%d%d", &n1, &n2)!=EOF){
        int revN1=getReverse(n1), revN2=getReverse(n2);
        int sum1 = n1+n2;
        if(revN1+revN2==getReverse(sum1)){
            printf("%d\n", sum1);
        } else {
            printf("NO\n");
        }
    }

    return 0;
}

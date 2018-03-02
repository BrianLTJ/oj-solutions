#include <stdio.h>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
    return a>b;
}
void numToArray(int numArray[],int N){
    for(int i=0;i<4;i++){
        numArray[i]=N%10;
        N = N/10;
    }
    sort(numArray, numArray+4, cmp);
}
int arrayToNum(int numArray[], bool isMax){
    int num=0;
    if(isMax){
        for(int i=0;i<4;i++){
            num=num*10+numArray[i];
        }
    } else {
        for(int i=3;i>=0;i--){
            num=num*10+numArray[i];
        }
    }
}
int main(){
    int N=0,numArray[4];
    scanf("%d", &N);
    do{
        numToArray(numArray, N);
        int maxNum=arrayToNum(numArray, true), minNum=arrayToNum(numArray, false);
        N = maxNum - minNum;
        printf("%04d - %04d = %04d\n", maxNum, minNum, N);
    }while(N!=6174 && N!=0);
    return 0;
}


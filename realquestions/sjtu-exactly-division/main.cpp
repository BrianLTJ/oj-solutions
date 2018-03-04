#include <stdio.h>
#include <vector>
#include <cmath>

bool primes[1001]={0};

bool isPrime(int n){
    if(n<2) return false;
    if(n==2) return true;
    int bound = (int)sqrt(n)+1;
    bool prime = true;
    for(int i=3;i<=bound;i++)
        if(n%i==0){
            prime = false;
            break;
        }
    return prime;
}

void calculatePrimes(){
    for(int i=2;i<1001;i++) {
        primes[i] = isPrime(i);
    }
}


int main(){
    int n,a;
    scanf("%d %d",&n, &a);
    calculatePrimes();

    int nFactors[1001]={0};

    // n! Factor decomposition

    // n!=1*2*...*k*(k+1)*...*n
    for(int k=2;k<=n;k++){
        int kRemaining = k;
        for(int j=2;j<kRemaining;j++){
            if(primes[j]){
                while(kRemaining%j==0){
                    nFactors[j]++;
                    kRemaining/=j;
                }
            }
        }
        // The Remaining part
        nFactors[kRemaining]++;
    }
/*
    printf("=====nFactors=====\n");
    for(int i=2;i<1001;i++)
        if(nFactors[i]) printf("%d^%d\n",i,nFactors[i]);
*/

    int aFactors[1001]={0};
    int aRemaining = a;
    for(int j=2;j<aRemaining;j++){
        if(primes[j]){
            while(aRemaining%j==0){
                aFactors[j]++;
                aRemaining/=j;
            }
        }
    }
    aFactors[aRemaining]++;
/*
    printf("=====aFactors=====\n");
    for(int i=2;i<1001;i++)
        if(aFactors[i]) printf("%d^%d\n",i,aFactors[i]);
*/

    int ak=0;
    bool akFeasible = true;

    // n^k >= a^k
    while(akFeasible){
        ak++;
        for(int i=2;i<1001;i++){
            if(nFactors[i] < aFactors[i]*ak){
                akFeasible = false;
                break;
            }
        }
        //printf("ak=%d, %s\n",ak,(akFeasible?"Yes":"No"));
    }
    ak--;
    printf("%d", ak);

    return 0;
}


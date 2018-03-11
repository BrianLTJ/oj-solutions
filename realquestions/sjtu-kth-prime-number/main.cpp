#include <iostream>
#include <algorithm>

using namespace std;
const int MAXNUM = 10000;
const int MAXMARK = MAXNUM*100;
int primes[MAXNUM+1];
bool primeMark[MAXMARK+1];

int curPrimeK=0;
int curPrimeMarkId=2;
void findPrime(int);

void findPrime(int k){
    if(curPrimeK>=k)
        return;

    while(curPrimeK<k){

        if(primeMark[curPrimeMarkId]){
            curPrimeK++;
            primes[curPrimeK]=curPrimeMarkId;

            for(int i=2;i*curPrimeMarkId<=MAXMARK;i++){
                primeMark[i*curPrimeMarkId]=false;
            }
        }

        curPrimeMarkId++;
    }

}

int main()
{
    int k;

    fill(primeMark, primeMark+MAXMARK, true);

    while(cin>>k){
        findPrime(k);

        cout << primes[k] << endl;
    }
    return 0;
}

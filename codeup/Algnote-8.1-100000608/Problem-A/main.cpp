#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXINT = 10;
int ans[MAXINT+1]={0};
int n;

void dfs(int numUsed[],int level){
    int countUseNum = 0; // Count numbers used in this layer
    int * numUsedNew = new int[n+1];
    memcpy(numUsedNew, numUsed, sizeof(int)*(n+1));
    for(int i=1;i<=n;i++){
        if(numUsedNew[i]==0){
            numUsedNew[i] = level;
            ans[level]=i;
            dfs(numUsedNew,level+1);
            countUseNum++;
            numUsedNew[i] = 0;
        }
    }
    if(countUseNum==0) {
        for(int i=1;i<=n;i++){
            cout << (i>1? " ":"")<<ans[i];
        }
        cout << endl;
    }
    delete(numUsedNew);
}

int main()
{
    cin >> n;
    int * numUsed = new int[n+1];
    fill(numUsed, numUsed+n+1,0);

    numUsed[0] = -1;

    dfs(numUsed,1);


    return 0;
}

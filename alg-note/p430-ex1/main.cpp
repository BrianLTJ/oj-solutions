#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

int A[MAXN], dp[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &A[i]);

    dp[0]=A[0];

    for(int i=1;i<n;i++){
        dp[i]=max(A[i],A[i]+dp[i-1]);
    }
    int k=0;
    for(int i=0;i<n;i++)
        if(dp[i]>dp[k])
            k=i;
    printf("%d\n", dp[k]);

    return 0;
}

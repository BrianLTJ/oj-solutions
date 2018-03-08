#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int MAXINT = 100;
int dp[MAXINT+1][MAXINT+1];

void findLCS(char str1[], char str2[]){
    for(int i=0;i<=MAXINT;i++){
        dp[i][0]=0; dp[0][i]=0;
    }
    int lenStr1 = strlen(str1);
    int lenStr2 = strlen(str2);
    for(int i=1;i<=lenStr1;i++){
        for(int j=1;j<=lenStr2;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            } else {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    printf("%d\n", dp[lenStr1][lenStr2]);
}

int main()
{
    char str1[MAXINT], str2[MAXINT];
    while(scanf("%s%s", &str1, &str2)!=EOF){
        //printf("%s %s\n", str1, str2);
        findLCS(str1, str2);
    }

    return 0;
}

#include <iostream>
#include <cstring>

using namespace std;
const int MAXLEN = 5000;
char orgStr[MAXLEN], procStr[MAXLEN];
int mapProcOrg[MAXLEN];
int dp[MAXINT][MAXINT]={0};

int main()
{
    cin >> orgStr;
    // Preprocess
    int orgStrLen = strlen(orgStr);
    int i,j;
    for(i=0;i<orgStrLen;i++){
        if(isalpha(orgStr[i])){
            procStr[j]=toupper(orgStr[i]);
            mapProcOrg[j]=i;
            j++;
        }
        if(isdigit(orgStr)){
            procStr[j]=orgStr[i];
            mapProcOrg[j]=i;
            j++;
        }
    }
    int procStrLen = strlen(procStr);
    for(int i=0;i<procStrLen;i++){
        for(int j=0;j<procStrLen;j++){

        }
    }

    return 0;
}

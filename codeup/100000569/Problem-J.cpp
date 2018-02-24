#include <stdio.h>
#include <cstring>
int main(){
    char str[3][100];
    int i=0, maxStr=2;
    for(i=0;i<3;i++)
        gets(str[i]);
    for(i=0;i<2;i++){
        maxStr = (strcmp(str[i],str[maxStr])>0)?i:maxStr;
    }
    puts(str[maxStr]);
    return 0;
}

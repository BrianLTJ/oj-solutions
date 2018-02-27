#include <stdio.h>
#include <cstring>
int minstr(char *str0,char *str1,char *str2) {
    int minid=0;
    if(strcmp(str0,str1)<0){
        if(strcmp(str0,str2)<0) minid=0;
        else minid =2;
    } else {
        if(strcmp(str1,str2)<0) minid=1;
        else minid=2;
    }
    return minid;
}
int main(){
    char str[3][21];
    for(int i=0;i<3;i++){
        gets(str[i]);
    }
    int minid[3] = {-1};
    minid[0]=minstr(str[0], str[1], str[2]);
    switch(minid[0]){
        case 0:
            if(strcmp(str[1],str[2])<0) {
                    minid[1]=1;minid[2]=2;
            } else{
                minid[1]=2;minid[2]=1;
            }
            break;
        case 1:
            if(strcmp(str[0],str[2])<0) {
                minid[1]=0; minid[2]=2;
            } else {
                minid[1]=2;minid[2]=0;
            }
            break;
        case 2:
            if(strcmp(str[0],str[1])<0) {
                minid[1]=0;minid[2]=1;
            } else {
                minid[1]=1;minid[2]=0;
            }
            break;
    }
    for(int i=0;i<3;i++)
        printf("%s\n", str[minid[i]]);
    return 0;
}

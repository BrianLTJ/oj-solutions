#include <stdio.h>
#include <cstring>
bool letterInRange(char letter){
    char tmp[10]={'a','e','i','o','u','A','E','I','O','U'};
    bool res = false;
    for(int i=0;i<10;i++){
        if(letter==tmp[i]){
            res = true;
            break;
        }
    }
    return res;
}
void extract(char str[], char result[]){
    int len = strlen(str),resid=0;
    for(int i=0;i<len;i++){
        if(letterInRange(str[i]))
            result[resid++]=str[i];
    }
    result[resid]='\0';
}

int main(){
    char str[100],res[100];
    gets(str);
    extract(str,res);
    puts(res);
    return 0;
}

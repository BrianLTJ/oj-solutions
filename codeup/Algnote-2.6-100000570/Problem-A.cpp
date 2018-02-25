#include <stdio.h>
#include <cstring>
void reverse(char str[], char result[]){
    int len = strlen(str);
    for(int i=0;i<len;i++){
        result[len-i-1]=str[i];
    }
    result[len] = '\0';
}
int main() {
    char str[100], result[100];
    gets(str);
    reverse(str,result);
    puts(result);
    return 0;
}

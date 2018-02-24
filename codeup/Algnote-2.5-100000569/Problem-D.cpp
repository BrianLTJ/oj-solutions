#include <stdio.h>
int main() {
    char str[100];
    gets(str);
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>96 && str[i]<123){
            // Lower case letter
            str[i]=219-str[i];
        }
        else if(str[i]>64 && str[i] < 91) {
            // Upper case letter
            str[i]=155-str[i];
        }
    }
    puts(str);
    return 0;
}

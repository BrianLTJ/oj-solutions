#include <stdio.h>
int main() {
    char s1[100], s2[100];
    gets(s1);
    gets(s2);
    bool equal = true;
    for(int i=0;s1[i]!='\0'&&s2[i]!='\0';i++){
        if(s1[i]!=s2[i]) {
            equal = false;
            printf("%d", s1[i]-s2[i]);
        }
    }
    if(equal) printf("0");
    return 0;
}

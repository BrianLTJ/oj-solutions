#include <stdio.h>
#include <cstring>
struct person {
    char name[20];
    int count;
} leader[3] = {"Li", 0, "Zhang", 0, "Fun", 0};

int main(){
    int n=0;
    scanf("%d", &n);
    char name[20];

    for(int i=0;i<n;i++){
        scanf("%s", name);
        for(int j=0;j<3;j++) {
            if(strcmp(leader[j].name, name)==0) {
                leader[j].count ++;
                break;
            }
        }
    }

    for(int k=0;k<3;k++)
        printf("%s:%d\n",leader[k].name, leader[k].count);
    return 0;
}

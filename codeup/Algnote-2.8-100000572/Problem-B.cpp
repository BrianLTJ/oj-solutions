#include <stdio.h>
#include <stdlib.h>
struct student {
    int num;
    char name[20];
    char sex;
    int age;
};

int main(){
    int n=0;
    scanf("%d", &n);
    struct student * s = new struct student[n];
    for(int i=0;i<n;i++) {
        scanf("%d %s %c %d",&s[i].num,s[i].name,&s[i].sex,&s[i].age);
    }
    for(int i=0;i<n;i++){
        printf("%d %s %c %d\n",s[i].num,s[i].name,s[i].sex,s[i].age);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct person {
    int num;
    char name[10];
    char sex;
    char job;
    union {
        int class;
        char position[10];
    }category;
};
int main(){
    int n=0;
    scanf("%d", &n);
    struct person * data = (struct person *)malloc(n * sizeof(struct person));
    for(int i=0;i<n;i++){
        // Input Data
        scanf("%d %s %c %c ", &data[i].num, &data[i].name, &data[i].sex, &data[i].job);
        if(data[i].job=='s'){
            scanf("%d",&data[i].category.class);
        } else if(data[i].job=='t') {
            scanf("%s", &data[i].category.position);
        }
    }

    for(int j=0;j<n;j++){
        // Input Data
        printf("%d %s %c %c ", data[j].num, data[j].name, data[j].sex, data[j].job);
        if(data[j].job=='s'){
            printf("%d", data[j].category.class);
        } else if(data[j].job=='t') {
            printf("%s", data[j].category.position);
        }
        printf("\n");
    }

    return 0;
}

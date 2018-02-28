#include <stdio.h>
struct student {
    int id;
    char name[20];
    int grade1;
    int grade2;
    int grade3;
};

void input(struct student * data, int n){
    for(int i=0;i<n;i++){
        scanf("%d %s %d %d %d", &data[i].id, &data[i].name, &data[i].grade1, &data[i].grade2, &data[i].grade3);
    }
}

void print(struct student * data, int n){
    for(int i=0;i<n;i++){
        printf("%d %s %d %d %d\n", data[i].id, data[i].name, data[i].grade1, data[i].grade2, data[i].grade3);
    }
}

int main(){
    struct student * data = new struct student [5];
    input(data, 5);
    print(data, 5);
    return 0;
}

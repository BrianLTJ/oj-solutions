#include <stdio.h>
struct student {
    int id;
    char name[20];
    int grade1;
    int grade2;
    int grade3;
};
int main(){
    student data[10];
    for(int i=0;i<10;i++) {
        scanf("%d %s %d %d %d", &data[i].id, &data[i].name, &data[i].grade1, &data[i].grade2, &data[i].grade3);
    }
    double g1=0.0,g2=0.0,g3=0.0;
    int maxid = 0,maxgrade=0;
    for(int i=0;i<10;i++){
        g1+=data[i].grade1; g2+=data[i].grade2; g3+=data[i].grade3;
        if((data[i].grade1+data[i].grade2+data[i].grade3)>maxgrade){
            maxid=i;
            maxgrade = data[i].grade1+data[i].grade2+data[i].grade3;}
    }
    g1=g1/10.0; g2=g2/10.0; g3=g3/10.0;
    printf("%.2f %.2f %.2f\n", g1, g2, g3);
    printf("%d %s %d %d %d\n",data[maxid].id,data[maxid].name,data[maxid].grade1,data[maxid].grade2,data[maxid].grade3);

    return 0;
}

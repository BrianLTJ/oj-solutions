#include <stdio.h>
int main(){
    int n1[2][3],n2[3][2], i=0, j=0;
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
            scanf("%d",&n1[i][j]);

    for(j=0;j<3;j++)
        for(i=0;i<2;i++)
            n2[j][i]=n1[i][j];

    for(j=0;j<3;j++){
        for(i=0;i<2;i++)
            printf("%d ", n2[j][i]);
        printf("\n");
    }

    return 0;
}

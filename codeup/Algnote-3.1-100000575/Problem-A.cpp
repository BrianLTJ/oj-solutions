#include <stdio.h>
#include <algorithm>
#define MAXL 10000
void removeTrees(bool trees[], int startp, int endp, int L) {
    for(int i=startp;i<=endp;i++)
        trees[i]=false;
}

int countTrees(bool trees[], int len){
    int treeNums = 0;
    for(int i=0;i<=len;i++)
        if(trees[i]) treeNums++;
    return treeNums;
}

int main(){
    int L=0,M=0;
    int r[1000],rid=0;
    scanf("%d %d", &L, &M);
    while(L>0&&M>0){
        bool * trees = new bool[L+1];
        for(int i=0;i<=L;i++)
            trees[i]=true;
        for(int i=0;i<M;i++){
            int startp=0, endp=0;
            scanf("%d %d", &startp, &endp);
            removeTrees(trees, startp, endp, L);
        }
        r[rid++]=countTrees(trees, L);
        scanf("%d %d", &L, &M);
    }
    for(int i=0;i<rid;i++)
        printf("%d\n", r[i]);
    return 0;
}

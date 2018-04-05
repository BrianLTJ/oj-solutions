#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 100;
//int uf[MAXN+1][2]; //[i][0]: parent, [i][1]: childNum

struct Node{
    int parent;
    int children[MAXN];
    int childNum;
    Node(){
        parent = 0;
        childNum = 0;
    }
};

Node uf[MAXN];

int main()
{
    int M = 0, N = 0;
    scanf("%d%d", &N, &M);

    for(int i = 0; i< M; i++){
        int id = 0, k = 0;
        scanf("%2d%d", &id, &k);
        uf[id].childNum = k;
        for(int j = 0; j < k; j++){
            int cid = 0;
            scanf("%2d", &cid);
            uf[cid].parent = id;
            uf[id].children[j] = cid;
        }
    }


    // Output
    int parent = 1;
    int nodeNum = 0;
    queue<int> q[2];
    int curQ = 0, nextQ = 1;
    q[curQ].push(1);
    while(!q[curQ].empty()){
        parent = q[curQ].front();
        // Traverse
        int childNum = uf[parent].childNum;
        if(childNum == 0){
            nodeNum ++;
        } else {
            for(int c = 0; c < childNum; c++){
                q[nextQ].push(uf[parent].children[c]);
            }
        }

        q[curQ].pop();

        // Switch Queue
        if(q[curQ].empty()){
            curQ = 1 - curQ;
            nextQ = 1 - nextQ;
            if(parent > 1) printf(" ");
            printf("%d", nodeNum);
            nodeNum = 0;
        }

    }
    return 0;
}

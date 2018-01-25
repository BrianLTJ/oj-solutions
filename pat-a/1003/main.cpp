#include <iostream>
#include <stdlib.h>
#define MAXCITY 500

using namespace std;


typedef struct ArcNode {
    int city, length;
    struct ArcNode *next;
} ArcNode;

typedef struct VetexNode { // Vetex
    int n;
    ArcNode * firstarc;
} VetexNode;

void queueInsert(int *, int&, int&, int, int);
int queuePop(int *,int &, int &, int);
bool isEmpty(int *,int &, int &, int);
int getVetexLen(VetexNode [], int, int);

int main()
{
    // Variables
    int N=0, M=0, C1=0, C2=0;
    int shortPathLen = 0;

    // Get Variables
    cin >> N >> M >> C1 >> C2;

    // Rescue team number
    int * resteam = new int[N];
    for(int i = 0;i<N;i++) {
        cin >> resteam[i];
    }

    // Init city nodes
    VetexNode *city=new VetexNode[N];
    for(int i=0;i<N;i++){
        city[i].n=i;
        city[i].firstarc=NULL;
    }

    // Load Road Map data
    for(int i = 0;i<N;i++){
        int city0=0,city1=0,l=0;
        cin >> city0 >> city1 >> l;

        // Add curPathLen
        shortPathLen += l;

        // Connect city0-1
        ArcNode *an1=(ArcNode *)malloc(sizeof(ArcNode));
        an1->city=city1;
        an1->length=l;
        an1->next = city[city0].firstarc;
        city[city0].firstarc=an1;
        // Connect city1-0
        ArcNode *an2=(ArcNode *)malloc(sizeof(ArcNode));
        an2->city=city0;
        an2->length=l;
        an2->next = city[city1].firstarc;
        city[city1].firstarc=an2;
    }

    // Fetch All Routes : C0->C1
    // Visit Queue
    int nqLen = N;
    int *nqueue = new int[nqLen];
    int nqfront=0,nqrear=0;

    bool *nvisited = new bool[N]; // Vertexes if Visited
    for (int i=0;i<N; i++) nvisited[i]=false;

    int pathNum = 0; // Current shortest paths number.
    int curPathLen = 0, curRescTeam = 0;  // Current search: path length with weight
    int *curPath = new int[N+1];
    int *curPathNodeCandidate = new int[N+1]; // Current Path: number of node candidates
    curPath[0]=0; // id of last vertex in curPath.

    // Insert c1 to queue
    queueInsert(nqueue, nqfront, nqrear, nqLen, C1);


    // Visit
    while(nqfront!=nqrear){
        int cityNode = queuePop(nqueue, nqfront,nqrear,nqLen);
        nvisited[cityNode]=true;

        // Update curPath curPathLen

        if(cityNode!=C1) { // Not end




            int nodeCandidate = 0; // unvisited neighbors of this node

            // Add unvisited neighbors to queue
            ArcNode *p = city[cityNode].firstarc;
            while(p){
                if(!nvisited[p->city]){
                    queueInsert(nqueue,nqfront,nqrear,nqLen,p->city);
                    nodeCandidate++;
                }
            }

            curPathNodeCandidate[curPath[0]]= nodeCandidate;

        } else { // Path Reach C1

        }

    }







    // TEST: Display RoadMap
    for (int i=0;i<N;i++) {
        ArcNode *p=city[i].firstarc;
        while(p) {
            cout << i << " " << p->city << " " << p->length << endl;
            p=p->next;
        }
    }

    return 0;
}

int getVetexLen(VetexNode vList[], int c1, int c2){
    int len = -1;
    ArcNode *p=vList[c1].firstarc;
    while(p){
        if(p->city == c2) {
            len = p->length;
            break;
        } else {
            p=p->next;
        }
    }
    return len;
}

void queueInsert(int *q,int &qfront, int &qrear, int n , int value){
    if((qrear+1)%n!=qfront) { // if queue not full
        qrear = (qrear+1)%n;
        q[qrear]=value;
    }

}

int queuePop(int *q,int &qfront, int &qrear, int n){
    int value = -1; // default error;
    if(qrear!=qfront){ // queue is not empty
        value = q[qfront];
        qfront = (qfront+1)%n;
    }
    return value;
}

bool isEmpty(int *q,int &qfront, int &qrear, int n){
     return (qrear==qfront);
}

void printPath(int *q) {
    for(int i=1;i<=q[0];i++){
        cout << " " << q[i] ;
    }
    cout << endl;
}

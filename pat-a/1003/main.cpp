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



int main()
{
    // Variables
    int N=0, M=0, C1=0, C2=0;
    // Get Variables
    cin >> N >> M >> C1 >> C2;

    // Rescue team number
    int * resteam = new int[N];
    for(int i = 0;i<N;i++) {
        cin >> resteam[i];
    }

    // Road Map
    VetexNode *city=new VetexNode[N];
    for(int i=0;i<N;i++){
        city[i].n=i;
        city[i].firstarc=NULL;
    }

    // Load Road Map data
    for(int i = 0;i<N;i++){
        int city0=0,city1=0,l=0;
        cin >> city0 >> city1 >> l;

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


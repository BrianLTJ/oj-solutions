/*
Input

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.

Output

For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 2 1.5 1 2.9 0 3.2

*/

#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

typedef struct PolyNode{
    int n=0;
    float nk=0.0;
    struct PolyNode * next=NULL;
} * pnode;

int main()
{
    int k=0;
    pnode p[2][2]; //p[i][0] link head, p[i][1] link rear
    for(int i=0;i<2;i++){
        p[i][0]=NULL;
        p[i][1]=NULL;
        cin>>k;
        for(int j=0;j<k;j++){
            pnode nd;
            nd=(pnode)malloc(sizeof(struct PolyNode));
            if(j==0) {p[i][0]=nd;p[i][1]=nd;}
            else{
                p[i][1]->next=nd;
                p[i][1]=nd;
            }
            p[i][1]->next=NULL;
            cin >> p[i][1]->n >> p[i][1]->nk;
        }
    }
    //Merge
    int rk=0;
    pnode result[2];
    result[0]=NULL; result[1]=NULL;

    pnode pi[2]; //Traverse Pointer
    pi[0]=p[0][0]; pi[1]=p[1][0];

    while(pi[0]||pi[1]){
        int ni[2];
        for(int i=0;i<2;i++){
            ni[i]=(pi[i]?pi[i]->n:-1);
        }

        pnode nd;
        nd=(pnode)malloc(sizeof(struct PolyNode));
        nd->next = NULL;
        rk++;

        if(!result[0]){
            // Init result
            result[0]=nd;
            result[1]=nd;
        }else {
            result[1]->next=nd;
            result[1]=nd;
        }

        if(ni[0]==ni[1]){
            nd->n=pi[0]->n;
            nd->nk=pi[0]->nk+pi[1]->nk;
            pi[0]=pi[0]->next;
            pi[1]=pi[1]->next;
        } else {
            int id=(ni[0]>ni[1]?0:1); // Not-Empty link list id
            nd->n=pi[id]->n;
            nd->nk=pi[id]->nk;
            pi[id]=pi[id]->next;
        }
    }

    // Output result
    result[1]=result[0];
    cout << rk;
    while(result[1]){
        cout << " " << result[1]->n << " " << fixed << setprecision(1) << result[1]->nk;
        result[1]=result[1]->next;
    }

    return 0;
}

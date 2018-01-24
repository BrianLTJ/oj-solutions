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
    int n;
    float nk;
    struct PolyNode * next;
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
    /*
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
    */

    // Merge
    //Traverse pointer
    pnode pt[2];
    pt[0] = p[0][0];
    pt[1] = p[1][0];
    // K of result, aka number of non-zero terms
    int rk = 0;
    pnode r = (pnode)malloc(sizeof(struct PolyNode));
    r->next = NULL;
    r->n = -1;
    r->nk = 0.0;
    pnode rh =r;
    // p0, p1 not end
    while(pt[0] && pt[1]){
        if(pt[0]->n == pt[1]->n){
            // p0.n == pt1.n
            
            // p0+p1 != 0
            if ((pt[0]->nk + pt[1]->nk)!=0.0){
                r->n=pt[0]->n;
                r->nk=pt[0]->nk + pt[1]->nk;
                r->next=(pnode)malloc(sizeof(struct PolyNode));
                r=r->next;

                //Init new rnode
                r->next=NULL;
                r->n = -1;
                r->nk = 0.0;
                rk++;
            }

            pt[0]=pt[0]->next;
            pt[1]=pt[1]->next;

        } else {
            // p0.n != pt1.n
            // pick bigger n
            int i = ((pt[0]->n > pt[1]->n)?0:1);
            r->n=pt[i]->n;
            r->nk=pt[i]->nk;
            r->next=(pnode)malloc(sizeof(struct PolyNode));
            r=r->next;

            //Init new rnode
            r->next=NULL;
            r->n = -1;
            r->nk = 0.0;
            rk++;
            pt[i]=pt[i]->next;
        }
    }

    // p0 or p1 end
    int nePoly = (pt[0]==NULL)?1:0;
    while(pt[nePoly]){
        if(pt[nePoly]->nk!=0) {
            r->n=pt[nePoly]->n;
            r->nk=pt[nePoly]->nk;
            r->next=(pnode)malloc(sizeof(struct PolyNode));
            r=r->next;

            //Init new rnode
            r->next=NULL;
            r->n = -1;
            r->nk = 0.0;
            rk++;
        }
        pt[nePoly]= pt[nePoly]->next;
    }

    /*TEST*/
    // while(rh){
    //     cout <<rh->n<<" " << rh->nk << " ";
    //     rh=rh->next;
    // }
    // cout << endl;
    // return 0;
    /*END TEST*/

    pnode rp = rh;
    cout << rk;
    while(rp){
        // cout << " [HIT rp] " ;
        if(rp->n>-1) cout << " " << rp->n << " " << fixed << setprecision(1) << rp->nk;
        rp=rp->next;
    }

    return 0;
}

#include <iostream>
//#include <stdio.h>
#include <vector>

using namespace std;

/*
    * Calculate the sum of mat area
    *
    * l: start line no.
    * c: start column no.
    * w: width of sub mat.
    * h: height of sub mat.
    *
    * return: int, sum of elems in the submat
*/

//int getSum(vector<vector<int>> mat, int l, int c, int w,int h){
int getSum(int mat[][100], int l, int c, int w,int h){
    int sum = 0;

    for(int i=l;i<l+h;i++) {
        for(int j=c;j<c+w;j++){
            sum+=mat[i][j];
            //cout << i << ":" <<j<<" elem "<<mat[i][j]<<endl;
        }
    }
    return sum;
}

int main(){
    int M,N,K;
    cin >> N >> M >> K;
    //scanf("%d %d %d", &N, &M,&K);

    //vector<vector<int>> mat;
    int mat[100][100];
    for(int i=0;i<N;i++){

        for(int j=0;j<M;j++){
            /*int num;
            cin >> num;
            line.push_back(num);*/
            cin >> mat[i][j];
            //scanf("%d", &mat[i][j]);
        }
        //mat.push_back(line);
    }

   // cout << getSum(mat,1,1,1,1);

/* TEST output mat
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++)
            cout << mat[i][j]<<" ";
            //printf("%d ", mat[i][j]);
        printf("\n");
    }
 */

    bool found = false;
    int minArea = 10001; // Initial min Area: the max size of mat

    // Traverse all shapes of sub mat
    for(int h=1;h<=N;h++){
        if(found && h>=minArea) break;

        for(int w=1;w<=M;w++){
            bool foundThisShape = false;

            // If current size of sub mat is larger than found, quit this loop
            if(found && w*h>minArea) break;

            // Traverse a 10ll allowed sub mat
            for(int ln=0;ln<N-h+1;ln++){
                for(int co=0;co<M-w+1;co++)
                if((getSum(mat,ln,co,w,h)>=K) && w*h<minArea){
                    found = true;
                    minArea = w*h;
                    // found and exit this loop
                    foundThisShape = true;
                    break;
                }
                if(foundThisShape) break;
            }

        }
    }

    if(!found){
        minArea=-1;
    }

    cout << minArea;

    return 0;
}


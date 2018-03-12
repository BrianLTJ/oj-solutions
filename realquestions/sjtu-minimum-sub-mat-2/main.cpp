#include <cstdio>
#include <algorithm>

using namespace std;
const int MAXSIZE = 100;

int mat[MAXSIZE][MAXSIZE];
int lineSum[MAXSIZE] = {0};
int colSum[MAXSIZE] = {0};
int subMatSize[MAXSIZE][MAXSIZE] = {0}; /// submat starts from 0,0

int getSum(int line, int col, int size_line, int size_col){
    int sum = 0;
    /*for(int i=0; i<size_line; i++){
        for(int j=0; j < size_col; j++){
            sum += mat[i+line][j+col];
        }
    }*/
    int leftCol = max(0, col-1), rightCol = col+size_col-1;
    int topLine = max(0, line-1), botLine = line+size_line-1;
    sum = subMatSize[botLine][rightCol] + subMatSize[topLine][leftCol] - subMatSize[botLine][leftCol] - subMatSize[topLine][rightCol];
    return sum;
}


int main()
{
    int N, M, K, temp;
    int maxSum = 0, minSquare = -1, sum=0;
    scanf("%d%d%d", &N, &M, &K);
    for(int i = 0 ; i < N; i++){
        for( int j = 0; j < M; j++){
            scanf("%d", &temp);
            mat[i][j] = temp;
            //lineSum[i] += temp;
            //colSum[j] += temp;

            for(int x = i; x <= N; x++)
                for(int y = j; y <= M; y++)
                    subMatSize[x][y] += temp;

            sum += temp;
            if(temp >= maxSum){
                maxSum = temp;
            }
        }
    }

    if(sum < K) {
        printf("-1");
        return 0;
    }
    if(maxSum >= K){
        printf("1");
        return 0;
    }
    bool found = false;
    for(int s = 2; s <= N*M; s++){
        int maxi = (s < N ? s : N);
        /// Calculate the width and height of the sub matrix

        /// i: height(number of lines)
        for(int i = 1; i <= maxi; i++){
            /// j: width (number of columns)
            int j = s / i;
            if(i * j != s || j > M) continue;

            //printf("Try Square %d x %d\n", i, j);

            /// traverse all the possible start point

            /// l: line no
            int max_l = N-i, max_c = M-j;

            for(int l = 0; l <= max_l; l++){

                //if(lineSum[l] < K) continue;

                for(int c = 0; c <= max_c; c++){
                    //if(colSum[c]<K) continue;
                    //printf("Start from point %d,%d sum: %d \n", l, c, getSum(l,c,i,j));
                    if(getSum(l,c,i,j)>=K){
                        found = true;
                        minSquare = s;
                        break;
                    }
                }

                if(found) break;
            }
            /// End loop for finding start x, y


        if(found) break;
        } /// End loop for finding square

        if(found) break;
    }

    printf("%d", minSquare);

    return 0;
}

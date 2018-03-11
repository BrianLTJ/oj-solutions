#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <string>

using namespace std;
const int MAXLEN = 500;
const int MAXCITY = 100;
const int INFDIST = 1000;

/** Calculate Big 2 pow **/
/** To be more accuracy, result will be mod 1000000 */
int bigPow[MAXLEN+1]={0};

void initBigPow(){
    bigPow[0]=1;
    for(int i=1; i<MAXLEN+1; i++){
        bigPow[i] = bigPow[i-1]*2 % 100000;
    }
}

struct bigBin{
    bool bin[MAXLEN+1];
    bigBin() {
        fill(bin, bin+(MAXLEN+1), false);
    }
    bigBin(int k) {
        fill(bin, bin+(MAXLEN+1), false);
        bin[k]=true;
    }
    int getMod1E5(){
        if(bin[MAXLEN]) return -1;
        //2^17 = 131072
        int sum=0;
        for(int i=0;i<MAXLEN;i++){
            sum = sum + (bin[i]?bigPow[i]:0);
            sum = sum % 100000;
        }
        return sum%100000;
    }
    void set2k(int k){
        if(k>=0 && k<MAXLEN+1)
            bin[k]=true;
    }
    void unset2k(int k){
        if(k>=0 && k<MAXLEN+1)
            bin[k]=false;
    }
    void printBin(){
        for(int i=0;i<MAXLEN+1;i++)
            if(bin[i]) cout << " 2^"<<i<<" ";
    }
};


// if b1<b2 return true
bool cmpBigBin(bigBin & b1, bigBin & b2){
    for(int i=MAXLEN;i>=0;i--){
        if(b1.bin[i]!=b2.bin[i]){
            return (b1.bin[i]?false:true);
        }
    }
    return false;
}

void copyBigBin(bigBin & target, bigBin & source){
    for(int i=0;i<MAXLEN+1;i++)
        target.bin[i] = source.bin[i];
}


// Use Matrix to store graph
int G[MAXCITY+1][MAXCITY+1];

bigBin curOptDist[MAXCITY];

void dijkstra(int cityNum){

    bool visited[MAXCITY];
    fill(visited, visited+MAXCITY, false);
    visited[0]=true;

    for(int i=1;i<cityNum;i++)
        curOptDist[i].set2k(MAXLEN);

    bigBin curDist;

    int lastAddedCity=0;

    int curOptCity=0;

    for(int i=0;i<cityNum;i++){
        bigBin curLoopOptCityDist;
        curLoopOptCityDist.set2k(MAXLEN);
        /*cout << "Start city: "<<lastAddedCity<<endl;*/
        /// Current start point is lastAddedCity
        /// Update curOptDist
        for(int c=1;c<cityNum;c++){
            if(visited[c]) continue;
            int curdk=G[lastAddedCity][c];
            if(curdk>-1){
                /*cout << "city "<< lastAddedCity << " - " << c << " distance: 2^" << curdk << endl;*/
                /// lastAddedCity - c connected
                /// Increase curDist;
                curDist.set2k(curdk);

                if(cmpBigBin(curDist, curOptDist[c])){
                    /// Update curOptDist[c]
                    copyBigBin(curOptDist[c], curDist);
                    /*cout << "Update CurOptimumDistance for city " << c << ", dist:";
                    curOptDist[c].printBin();
                    cout<<endl;*/
                }

                /// Restore curDist
                curDist.unset2k(curdk);
            }

            /// Update the shortest city path in this loop
            if(cmpBigBin(curOptDist[c], curLoopOptCityDist)){
                curOptCity = c;
                copyBigBin(curLoopOptCityDist, curOptDist[c]);
            }

        }

        /// Select the shortest to be visited
        if(!visited[curOptCity]){
            visited[curOptCity]= true;
            lastAddedCity = curOptCity;
            copyBigBin(curDist, curLoopOptCityDist);
            /*cout << "Add city " << curOptCity << " to visited list";
            curDist.printBin();
            cout << endl;*/
        }
    }

}


int main()
{
    int N, M;
    int c1, c2;
    cin >> N >> M;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            G[i][j]=(i==j?0:-1);
    for(int i = 0; i < M; i++){
        cin >> c1 >> c2;
        //if(G[c1][c2]>-1||G[c2][c1]>-1) cout << "ERROR:Dup G: " << c1 << "-"<<c2<<endl;
        if(G[c1][c2]>-1||G[c2][c1]>-1){
            if(G[c1][c2]<i){
                continue;
            }
        }
        G[c1][c2]=i;
        G[c2][c1]=i;
    }
    dijkstra(N);
    initBigPow();
    /*for(int i=1;i<N;i++){
        cout << "City: " << i << " ";
        curOptDist[i].printBin();
        cout << endl;
    }*/
    for(int i=1;i<N;i++)
        cout << curOptDist[i].getMod1E5() << endl;
    return 0;
}

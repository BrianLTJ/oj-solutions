#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int MAXINT = 21;
int main()
{
    int n,r;
    cin >> n >> r;
    int level = 0;
    bool * numUsed = new bool[n+1];
    fill(numUsed, numUsed+n+1, false);
    int * ans = new int[n];
    queue<int> availNums[MAXINT];
    // insert into availNums level 0
    for(int i=1;i<=(n-r+1);i++)
        availNums[0].push(i);

    while(!availNums[0].empty()||level>0){
        if(!availNums[level].empty()) {
            int curNum = availNums[level].front();
            availNums[level].pop();
            ans[level] = curNum;
            //cout << "Cur Level:" << level << ",Cur Num:" << curNum << endl;

            if(level==r-1){
                // output
                for(int i=0;i<r;i++)
                    cout<< (i>0?" ":"")<<ans[i];
                cout << endl;


                if(availNums[level].empty())
                    // go back to last level
                    level--;

            } else if (level<r-1) {
                level++;
                // Clear queue[level+1]
                while(!availNums[level].empty()) availNums[level].pop();

                for(int i=curNum+1;i<=n-r+level+1;i++)
                    availNums[level].push(i);

            }
        } else {
            level = (level>0?level-1:0);
        }
    }

    return 0;
}

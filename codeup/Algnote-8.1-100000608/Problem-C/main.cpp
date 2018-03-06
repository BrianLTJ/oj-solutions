#include <iostream>
#include <cmath>

using namespace std;
const int MAXINT = 20;
int ans = 0;
int nums[MAXINT]={0};
int n,k;

bool isPrime(int n){
    bool ret = true;
    int boundary = (int)sqrt(n*1.0);
    for(int i=2;i<=boundary;i++){
        if(n%i==0) {
            ret = false;
            break;
        }
    }
    return ret;
}
/*
 * Calc
 *
 * startId: The start id of allowed numbers 0..n-1
 * curSum: Current Accumulated sum
 * index: The index of current add number 0..k-1
 *
*/
void calc(int startId, int curSum, int index) {
    //cout << "Loop for number["<<startId<<"], index:"<<index<<endl;
    if(index==k){
        // curSum is the sum of k nums
        //cout << "CurSum:"<<curSum<<endl;
        if(isPrime(curSum)) ans++;
        return;
    }
    if(index>k||startId>=n) return;
    // Select nums[startID]
    calc(startId+1,curSum+nums[startId],index+1);
    // Not select nums[startID]
    calc(startId+1,curSum,index);
}

int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> nums[i];

    calc(0,0,0);

    cout << ans;
    return 0;
}

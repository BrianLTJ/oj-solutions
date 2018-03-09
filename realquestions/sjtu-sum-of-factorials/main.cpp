#include <iostream>

using namespace std;

void judge(int n){
    int curX = 2;
    int temp = n;
    //int loopCount = 0;
    // Test if need 0!/1!
    if(temp%2!=0){
        temp--;
    }
    // Can only split one item out (temp-1)
    while(temp%curX==0){
        //loopCount++;
        temp=temp/curX;
        // if n has curX!, split it out
        if(temp>1 && temp%(curX+1)!=0){
            temp--;
        }
        curX++;
    }
    //printf("LoopCount:%d\n", loopCount);
    if(temp==1){
        //printf("YES\n");
        cout << "YES" << endl;
    } else{
        //printf("NO\n");
        cout << "NO" << endl;
    }
}

int main()
{
    int n = 0;
    while(cin>>n) {
        judge(n);
    }
    return 0;
}

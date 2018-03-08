#include <iostream>

using namespace std;
int fb[31]={-1};
int F(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    //cout << "Calc F" << n << endl;
    if(fb[n]!=0){
        return fb[n];
    } else {
        fb[n]=F(n-1)+F(n-2);
        return fb[n];
    }

}

int main()
{
    fb[0]=1; fb[1]=1;
    int n;
    cin >> n;
    cout << F(n) <<endl;
    return 0;
}

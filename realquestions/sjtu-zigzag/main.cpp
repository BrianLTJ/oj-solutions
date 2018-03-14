#include <iostream>

const int MAXENUM = 50;
using namespace std;

int main()
{
    int n;
    int num[MAXENUM] = {0};
    int numDiff[MAXENUM] = {0};
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        if(i>0) numDiff[i-1] = num[i] - num[i-1];
    }
    return 0;
}

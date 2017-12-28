#include <iostream>
#include <vector>
using namespace std;

#include "1.two-sum.cpp"

int main(){
    Solution a;
    vector<int> acc={1,5,8,9,3};
    vector<int> r=a.twoSum(acc,10);
    for(int i=0;i<r.size();i++){
        cout<<r[i]<<endl;
    }
    return 0;
}

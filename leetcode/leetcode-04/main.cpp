#include <iostream>
#include <vector>

using namespace std;

#include "4.median-of-two-sorted-arrays.cpp"

int main()
{
    vector<int> a={1,3,8,9,12,18,26,39,44};
    vector<int> b={3,4,7,10};
    Solution c;
    cout<<c.findMedianSortedArrays(a,b)<<endl;
    return 0;
}

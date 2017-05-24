/*
1001 - Another A+B

DESCRIPTION
Give you an integer a, you are to find two another integers which sum is a.

INPUT
Multiply Cases. For each line, there is an Integer a.

OUTPUT
For each test case, you should two Integers b and c, and b+c=a in each line.

SAMPLE INPUT
10
11

SAMPLE OUTPUT
1 9
3 8

*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    /* code */
    int a;
    vector<int> inp;
    while(!cin.eof()){
        cin>>a;
        cout << a<<endl;
        inp.push_back(a);
    }
    for(int i=0;i<inp.size();i++){
        cout<<inp[i]<<endl;
    }
    return 0;
}


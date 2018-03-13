#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

int convInt(const string & str){
    int num = 0, p = 0;
    int imax = numeric_limits<int>::max();
    int imin = numeric_limits<int>::min();
    //cout << imax << " " << imin << endl;
    bool allowSymbol = true, positive = true, found = false;
    bool of = false;
    while(p<str.size()){
        char c = str[p];
        //cout << "Dealing with " << c << endl;
        if(c>='0' && c<='9') {
            found = true;
            allowSymbol = false;
            int n = c - '0';
            /// TODO Judge whether num will exceed int limit
            switch(positive){
                case true:
                    /// Overflow
                    if((imax - n) / 10 < num) {
                        of = true;
                    }
                    break;
                case false:
                    /// Overflow
                    if((imin + n) / 10 > (-num)){
                        of = true;
                    }
                    break;
            }
            if(of){
                /// Overflow, then exit
                break;
            }
            num = num * 10 + n;
        } else if((allowSymbol && c == '-') || (allowSymbol && c == '+')){
            positive = (c=='-'?false:true);
        } else{
            if(found) break;
            // Clear positive
            positive = true;
        }
        p++;
    }

    if(!positive) num = -num;
    if(!found || of) num = -1;
    return num;
}

int main()
{
    string str;
    cin >> str;
    cout << convInt(str);


    return 0;
}

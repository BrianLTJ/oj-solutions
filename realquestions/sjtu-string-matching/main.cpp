#include <iostream>
#include <string>
using namespace std;
int main(){
    string str,pattern;
    cin>>str>>pattern;
    long bound=str.length()-pattern.length()+1;
    long len = str.length();
    long count = 0;
    for(long i=0;i<bound;i++){
        long pos = str.find(pattern,i);
        if(pos!=string::npos){
            count++;
            // jump to the found position
            i=pos+1;
        } else {
            // Cannot find pattern in remaining string
            break;
        }
    }
    cout << count;
    return 0;
}

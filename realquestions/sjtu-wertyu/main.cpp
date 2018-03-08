#include <iostream>
#include <cstring>
#include <map>

using namespace std;
map<char, char> mp;

int main()
{
    /*Init mp*/
    char keys[4][15]={
        "`1234567890-=\0",
        "QWERTYUIOP[]\\\0",
        "ASDFGHJKL;\'\0",
        "ZXCVBNM,./\0"
    };
    for(int i=0;i<4;i++){
        int bound = strlen(keys[i]);
        for(int j=1;j<bound;j++)
            mp[keys[i][j]]=keys[i][j-1];
    }
    // Add space
    mp[' ']=' ';

    string rawStr, convStr;
    getline(cin,rawStr);
    int len=rawStr.length();
    for(int i=0;i<len;i++){
        convStr=convStr+mp[rawStr[i]];
    }
    cout << convStr;
    return 0;
}

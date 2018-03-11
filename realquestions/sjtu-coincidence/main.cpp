#include <iostream>
#include <cstring>

using namespace std;
const int MAXLEN = 100;
int cmp[MAXLEN+1][MAXLEN+1]={0};
void genCmp(const string s1, const string s2){
    for(int i=0;i<s1.length();i++){
        for(int j=0;j<s2.length();j++){
            if(s1[i]==s2[j]){
                cmp[i+1][j+1]=cmp[i][j]+1;
            } else {
                cmp[i+1][j+1]=max(cmp[i][j+1], cmp[i+1][j]);
            }
        }
    }

}

int main()
{
    string s1, s2;

    cin>>s1>>s2;
    genCmp(s1, s2);
    cout << cmp[s1.length()][s2.length()];
    return 0;
}

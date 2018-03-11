#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string & s1, string & s2){
    int i=0;
    while(s1[i]==s2[i]&&i<min(s1.length(),s2.length())){
        i++;
    }
    if(i<min(s1.length(),s2.length())){
        return s1[i]<s2[i];
    } else {
        return s1.length()<s2.length();
    }
}

int main()
{
    string str;
    cin >> str;
    vector<string> suffix;
    for(int i=0;i<str.length();i++)
        suffix.push_back(str.substr(i));
    sort(suffix.begin(), suffix.end(), cmp);
    for(int i=0;i<suffix.size();i++)
        cout << suffix[i] << endl;
    return 0;
}

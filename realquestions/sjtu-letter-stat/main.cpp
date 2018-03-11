#include <iostream>
#include <cstring>

using namespace std;

void stat(const string str){
   int cnt[26]={0};
   int len = str.length();
   for(int i=0;i<len;i++){
        if(str[i]>='A'&& str[i]<='Z'){
            cnt[str[i]-'A']++;
        }
   }
   for(int i=0;i<26;i++)
    cout << (char)('A'+i) << ":" << cnt[i] << endl;

}

int main()
{
    string str;
    while(cin>>str){
        stat(str);
    }
    return 0;
}

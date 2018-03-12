#include <iostream>

using namespace std;

const int MAXFACT = 10;
int factorials[MAXFACT + 1];

void InitFactorials(){
    factorials[0] = 1;
    for(int i = 1; i <= MAXFACT; i++)
        factorials[i] = factorials[i-1] * i;
}

bool judge(int n){
    int tmp = n;
    for(int i = MAXFACT; i >=0; i--){
        if(tmp >= factorials[i])
            tmp -= factorials[i];

        if(tmp == 0)
            break;
    }
    return tmp == 0;
}

int main()
{
    int n;
    InitFactorials();
    while(cin >> n) {
        if(judge(n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

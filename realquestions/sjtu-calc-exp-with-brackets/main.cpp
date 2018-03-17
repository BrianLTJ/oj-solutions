#include <iostream>
#include <cstring>
#include <iomanip>
#include <stack>
#include <vector>
#include <regex>

using namespace std;

struct node {
    double num;
    char op;
    bool isOp;
    node() {
        isOp = false;
        num = 0.0;
    }
    node(double _n) {
        num = _n;
        isOp = false;
    }
    node(char _op) {
        op = _op;
        isOp = true;
    }
};

int main()
{
    string exp;
    cin >> exp;

    string ops = "+|-|*|/|(|)";

    stack<node> opStack;
    vector<node> postExp;




    cout.setf(ios::fixed);
    cout << setprecision(3) << 688.315263 << endl;
    return 0;
}

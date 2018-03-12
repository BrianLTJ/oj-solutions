#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

struct Node {
    char op;
    double num;
    bool isOp; // true: node类型为op， false: node类型为操作数
    Node(char _op) {
        op = _op;
        isOp = true;
    }
    Node(int _num) {
        num = _num;
        isOp = false;
    }
    Node() {
        isOp = false;
        num = 0.0;
    }
    void clear() {
        isOp = false;
        num = 0.0;
        op = ' ';
    }
};

map<char, int> opPriority;

double CalcExp(const string exp){
    queue<Node> stPostexp;
    stack<Node> stOp;

    int expLen = exp.length();
    Node temp;
    for(int i = 0; i < expLen; i++){
        if( isdigit( exp[i] ) ) {
            temp.isOp = false;
            temp.num = temp.num * 10 + exp[i] - '0';
            if(i == expLen - 1) {
                stPostexp.push(temp);
                ////cout << "Push number " <<temp.num<<" to stack" << endl;
            }
        } else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            /// Current temp node has been used
            if(!temp.isOp){
                /// Push current temp(number) to post exp
                stPostexp.push(temp);
                ////cout << "Push number " <<temp.num<<" to stack" << endl;
            }

            /// Clear temp
            temp.clear();

            /// Add current op to temp
            temp.isOp = true;
            temp.op = exp[i];

            /// Pop stOp to stPostexp when current op priority <= top op priority
            while(!stOp.empty() && opPriority[temp.op] <= opPriority[stOp.top().op]){
                stPostexp.push(stOp.top());
                ////cout << "Push op " <<stOp.top().op<<" to stack" << endl;
                stOp.pop();
            }

            /// Compare priority
            if( stOp.empty() || !stOp.empty() && opPriority[temp.op] > opPriority[stOp.top().op]) {
                /// Push current op to stack
                stOp.push(temp);
                ////cout << "Push op " <<temp.op<<" to opstack" << endl;

            }

            temp.clear();
        }

    } /// End scanning exp
    while(!stOp.empty()) {
        stPostexp.push(stOp.top());
        stOp.pop();
    }


    /// Calc Post exp
    stack<Node> s;
    temp.clear();
    Node cur;
    while(!stPostexp.empty()){
        cur = stPostexp.front();
        stPostexp.pop();
        if(!cur.isOp) //是操作数，压入栈
            s.push(cur);
        else {
            /// op, calculate
            double tmp1, tmp2;
            tmp2 = s.top().num;
            s.pop();
            tmp1 = s.top().num;
            s.pop();
            temp.clear();
            temp.isOp = false;
            switch(cur.op) {
                case '+':
                    temp.num = tmp1 + tmp2;
                    break;
                case '-':
                    temp.num = tmp1 - tmp2;
                    break;
                case '*':
                    temp.num = tmp1 * tmp2;
                    break;
                case '/':
                    temp.num = tmp1 / tmp2;
                    break;
            }
            s.push(temp);
        }
    }  /// End scan post exp queue
    return s.top().num;
}

int main()
{
    string exp;
    opPriority['+'] = 1;
    opPriority['-'] = 1;
    opPriority['*'] = 2;
    opPriority['/'] = 2;
    while(cin >> exp) {
        cout << CalcExp(exp) << endl;
    }

    return 0;
}

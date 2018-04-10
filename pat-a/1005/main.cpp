#include <cstdio>
#include <stack>

using namespace std;

int main()
{

    long long n = 0;
    scanf("%ld", &n);
    int sum = 0;
    while(n>0){
        sum = sum + (n%10);
        n = n / 10;
    }
    printf("%d\n", sum);
    char num[10][8] = {"zero\0", "one\0", "two\0", "three\0", "four\0", "five\0", "six\0", "seven\0", "eight\0", "nine\0"};
    stack<int> s;
    while(sum>0){
        s.push(sum%10);
        sum = sum / 10;
    }
    bool first = true;
    while(!s.empty()){
        if(!first){
            printf(" ");
        } else {
            first = false;
        }
        printf("%s", num[s.top()]);
        s.pop();
    }

    return 0;
}

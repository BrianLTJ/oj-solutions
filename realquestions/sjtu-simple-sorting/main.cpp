#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int MAXM = 1000;

bool cmp(int a, int b) {
    return a<b;
}

int main()
{
    int n;
    scanf("%d", &n);
    int * rawNums = new int[n];
    for(int i=0;i<n;i++)
        scanf("%d", &rawNums[i]);


    vector<int> toSort;

    // filter out duplicates
    bool occur[MAXM+1];
    fill(occur, occur+MAXM+1, false);
    for(int i=0;i<n;i++){
        if(!occur[rawNums[i]]){
            occur[rawNums[i]] = true;
            toSort.push_back(rawNums[i]);
        }
    }



    // sort
    sort(toSort.begin(),toSort.begin()+toSort.size(), cmp);

    // output
    int sortedLen = toSort.size();
    printf("%d", toSort[0]);
    for(int i=1;i<sortedLen; i++){
        printf(" %d", toSort[i]);
    }
    return 0;
}

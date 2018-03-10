#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAXM = 20;
const int MAXSEQ = 26;

long long factorial[MAXM+1]={0};

struct node{
    char data;
    node * child[MAXM];
    node() {
        for(int i=0;i<MAXM;i++)
            child[i]=NULL;
    }
};

void initFactorial(){
    factorial[0]=1;
    for(long long i=0;i<(sizeof(factorial)/sizeof(long long));i++){
        factorial[i]=i*factorial[i-1];
    }
    //cout << "Factorial Inited " << sizeof(factorial)/sizeof(long long) << " units" << endl;
}

long long Combination(int n, int r){
    long long ret=1;
    for(int i=r+1;i<=n;i++)
        ret*=i;

    for(int i=2;i<=n-r;i++){
        ret/=i;
    }
    return ret;
    //return factorial[n]/(factorial[r]*factorial[n-r]);
}


long long countP(const string pre, const string post, const int m){
    if(pre.length()==1) return 1;
    // Find Root
    vector<string> layerNodePost, layerNodePre;
    //char root = pre[0];
    string tempPost = post.substr(0, post.length()-1);
    string tempPre = pre.substr(1);
    while(tempPost.length()>0){
        string subPre, subPost;
        char subRoot = tempPre[0];
        int subRootInPost = tempPost.find(subRoot);
        int subLen = subRootInPost+1;
        subPost = tempPost.substr(0, subLen);
        subPre = tempPre.substr(0, subLen);
        layerNodePre.push_back(subPre);
        layerNodePost.push_back(subPost);

        /// TEST
        //cout << subPre << " " << subPost << endl;
        // Update new temp
        tempPost = tempPost.substr(subLen);
        tempPre = tempPre.substr(subLen);
        //cout << "TEMP: " << tempPre << " " << tempPost << endl;
    }

    long long ret = Combination(m, layerNodePre.size());
    for(int i=0;i<layerNodePre.size();i++){
        ret = ret * countP(layerNodePre[i], layerNodePost[i], m);
    }
    return ret;

}

int main()
{
    int m;
    string pre, post;
    initFactorial();
    while(cin>>m>>pre>>post && m!=0){
        cout << countP(pre,post,m)<<endl;
    }
    return 0;
}

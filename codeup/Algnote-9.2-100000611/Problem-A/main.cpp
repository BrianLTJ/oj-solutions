#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#define MAXLEN 10000
using namespace std;

struct node {
    char data;
    struct node * left;
    struct node * right;
    /*node() {
        left = NULL;
        right = NULL;
    }*/
};

node * rebuildTree(const string & preorder, const string & inorder){
    node *p = new node;
    if(preorder.length()==0||inorder.length()==0)  return nullptr;
    else {
        p->data = preorder[0];
        string leftpre = preorder.substr(1,inorder.find(p->data));
        string leftin = inorder.substr(0,inorder.find(p->data));
        string rightpre = preorder.substr(inorder.find(p->data)+1);
        string rightin = inorder.substr(inorder.find(p->data)+1);
        p->left = rebuildTree(leftpre, leftin);
        p->right = rebuildTree(rightpre, rightin);
    }
    return p;
}

void postTraverse(node * root){
    if(root!=NULL){
    postTraverse(root->left);
    postTraverse(root->right);
    cout<<root->data;
    }
}


int main(){
    string preorder, inorder;
    //char preorder[MAXLEN], inorder[MAXLEN];
    vector<string> results;
    //while(scanf("%s %s", &preorder, &inorder)!=EOF){
    while(cin>>preorder>>inorder){
        //printf("%s %s\n", preorder, inorder);
        node * root = rebuildTree(preorder, inorder);
        postTraverse(root);
        cout<<endl;
    }
    return 0;
}

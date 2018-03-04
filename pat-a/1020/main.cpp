#include <iostream>
#include <vector>
#include <queue>
#define MAXINT 31

using namespace std;
int postorder[MAXINT]={-1}, inorder[MAXINT]={-1};
vector<int> preorder;


struct node{
    int data;
    struct node * left;
    struct node * right;
   /* node() {
        left = NULL;
        right = NULL;
    }*/
};

int findElem(int nums[], int elem, int startp=0, int length=MAXINT){
    int id = -1;
    for(int i=startp;i<length-startp;i++)
        if(nums[i]==elem) {id=i; break;}
    return id;
}
/*
 * Rebuild Tree
 * postL postR: postorder seq start(L) end (R) L:R
 * inL inR: inorder seq start(L) end(R) L:R
 */
node * rebuildTree(int postL, int postR, int inL, int inR){
    /*cout << "Cur Build: post in"<<endl;
    cout << postL << postR << inL << inR << endl;*/
    if((postL>postR) || (inL>inR)) {/*cout<<"EXIT Cur Loop"<<endl;*/ return nullptr;}
    node *p = new node;
    p->data = postorder[postR];
    int leftInL = inL;
    int inorderRootId=findElem(inorder,p->data,inL);
    int leftInR=inorderRootId-1;

    int rightInL=leftInR+2;
    int rightInR=inR;
    int leftPostL=postL;
    int leftPostR=leftPostL+(leftInR-leftInL);
    int rightPostL=leftPostR+1;
    int rightPostR=postR-1;
   /* cout <<"LEFT POST IN"<<endl;
    cout<<leftPostL<<leftPostR<<leftInL<<leftInR<<endl;
    cout <<"RIGHT POST IN"<<endl;
    cout<<rightPostL<<rightPostR<<rightInL<<rightInR<<endl;*/
    p->left=rebuildTree(leftPostL,leftPostR,leftInL,leftInR);
    p->right=rebuildTree(rightPostL,rightPostR,rightInL,rightInR);
    return p;

}

void traversePreOrder(node * root){
    if(root!=NULL){
        preorder.push_back(root->data);
        traversePreOrder(root->left);
        traversePreOrder(root->right);
    }
}

void traverseLevelOrder(node * root){
    if(root!=NULL){

    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>postorder[i];
    for(int i=0;i<n;i++)
        cin>>inorder[i];
    node *root;
    root = rebuildTree(0,n-1,0,n-1);

    vector<int> levelorderId;
    queue<node*> levelorderQueue;

    levelorderQueue.push(root);

    while(!levelorderQueue.empty()){
        node * p = levelorderQueue.front();
        levelorderId.push_back(p->data);
        if(p->left!=NULL)
            levelorderQueue.push(p->left);
        if(p->right!=NULL)
            levelorderQueue.push(p->right);
        levelorderQueue.pop();
    }
    cout << levelorderId[0];
    for(int i=1;i<levelorderId.size();i++)
        cout << " " << levelorderId[i];

    return 0;
}

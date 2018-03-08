#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

/** Structure of node to store pows */
struct powNode{
    int pow;
    struct powNode * left;
    struct powNode * right;
    powNode(){
        pow = 0;
        left = NULL;
        right = NULL;
    }
    powNode(int p){
        pow = p;
        left = NULL;
        right = NULL;
    }
};

powNode* split(int n){
    if(n==0||n==1) return NULL;
    powNode * head = NULL;
    powNode * tail = NULL;
    if(n%2==1){
        // Odd number
        // Create 2^0
        tail = new powNode;
        tail->pow=0;

        // Get 2^(n-1)
        head = split(n-1);
        // It's 2^0
        if(head==NULL) head=tail;
        else {
            //link
            powNode *p=head;
            while(p->right!=NULL)
                p=p->right;
            p->right=tail;
        }
    } else {
        // Even Number
        int curPow = 0; // Current Pow for all unsettled items
        int curN = n;
        while(curN%2==0){
            // while curN is even
            curPow++;
            curN=curN/2;
        }
        // occurs a 2^curPow*2^0
        tail = new powNode(curPow);
        tail->left = split(curPow);

        head = split(n-(int)pow(2.0,curPow));
        // if head is null
        if(head==NULL){
            head = tail;
        } else {
            // Traverse head link
            powNode * p=head;
            while(p->right!=NULL){
                // if the pow larger than 1, split
                /*if(p->pow>1&&p->left==NULL)
                    p->left=split(p->pow);*/
                p=p->right;
            }
            // link tail to head link
            p->right = tail;
        }
    }
    return head;
}


void traverse(powNode* root){
    if(root==NULL) return;
    if(root->pow > 1) {
        cout << "2(";
        traverse(root->left);
        cout << ")";
    } else if (root->pow == 1){
        cout<<"2";
    } else {
        cout << "2(0)";
    }
    if(root->right!=NULL){
        cout << "+";
        traverse(root->right);
    }

}

void preTraverse(powNode * root){
    if(root==NULL) return;
    cout << root->pow << " ";
    preTraverse(root->left);
    preTraverse(root->right);
}

int main()
{
    int n;
    cin >> n;
    powNode * root = split(n);

    /**TEST*/
    //preTraverse(root);
    // Traverse tree and output
    traverse(root);
    return 0;
}

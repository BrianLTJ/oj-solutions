#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXLEN = 51;
const int MAXFOLDER = 15;
struct Folder;
struct Node;

struct Folder{
    char name;
    Node * child;
    Folder(){
        child = NULL;
    }
};

struct Node{
    Folder f[MAXFOLDER];
    int num;
    Node(){
        num = 0;
    }
};

Node* findFolderChild(Node * root, char name[]){
    if(root == NULL) return NULL;
    for(int i=0;i < root->num; i++){
        if(strcmp(name, root->f[i].name)==0)
            return root->f[i].child;
    }

    return NULL;
}

int splitPath(char path[], char folders[MAXLEN][MAXLEN])


void buildTree(char path[], Node* root){
    Node * p = root;
    char tempPath[MAXLEN];
    strcpy(tempPath, path);
    while(strlen(tempPath)>0){
        /// Get folder name
        char fname[MAXLEN];
        int i;
        while()
        Node * tmp = findFolderChild(p, )

    }


}




int main()
{
    char temp[MAXLEN];
    int n;
    Node* root = NULL;
    while(scanf("%d", &n)!=EOF){
        for(int i=0; i < n; i++){
            gets(temp);
            buildTree(temp, root);
        }
    }
    return 0;
}

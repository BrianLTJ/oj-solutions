#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXFOLDER = 15;

struct layerNode;
struct folderNode;

struct folderNode{
    string folderName;
    layerNode * child;
    folderNode(){
        child = NULL;
    }
    folderNode(string name){
        folderName = name;
        child = NULL;
    }
};

struct layerNode {
    vector<struct folderNode> folders;
};

layerNode* findFolderChild (layerNode * layer, const string & folderName){
    if(layer==NULL) return NULL;
    for(int i=0;i<layer->folders.size();i++){
        folderNode *p = &layer->folders[i];
        //cout << p->folderName << endl;
       // cout << "Searching for " << folderName<< ", current with " << p->folderName<<endl;
        if(p->folderName==folderName){
            //cout << "Found " << folderName << endl;
            return p->child;
        } else {
            //cout << "Not match: current with " << p->folderName<<endl;
        }
    }
    // Cannot find
    return NULL;
}

void buildFileTree(layerNode * root, const string & path) {
    string tempPath = path;
    layerNode * curLayer = root;
    while(tempPath.length()>0){
        // Find Folder name
        int flagPos = tempPath.find('\\');
        if(flagPos==string::npos) flagPos=tempPath.length();

        string folderName = tempPath.substr(0,flagPos);

        //cout << path << " : Current dealing with folder :" << folderName << endl;

        if(folderName.length()>0){
            // Add folder node
            layerNode * folder = findFolderChild(root, folderName);

            if(folder == NULL){
                // Not Found folder
                // Create one
                folderNode newFolder(folderName);
                newFolder.child = new layerNode;
                curLayer->folders.push_back(newFolder);
                curLayer = newFolder.child;

            } else {
                // Find folder
                // folder point to its child
                curLayer = folder;
            }

        }
        if(tempPath.find('\\')!=string::npos)
            tempPath = tempPath.substr(flagPos+1);
        else break; // String search end
    }
}

bool cmpFolderNode(folderNode & f1, folderNode &f2){
    return f1.folderName<f2.folderName;
}

void printTree(layerNode * root, int level){
    if(root==NULL) return;
    //string preBlank;
    // Sort same layer folders
    sort(root->folders.begin(), root->folders.end(), cmpFolderNode);

    //cout << "[LAYER START]"<< endl;
    for(int i=0;i<root->folders.size();i++){
        for(int i=0;i<level;i++){
            cout << " ";
        }
        folderNode * f = &root->folders[i];
        cout << /*preBlank << */f->folderName << endl;
        printTree(f->child,level+1);
    }
    //cout << "[LAYER END]" << endl;
}

int main()
{
    int n;
    while(1){
        cin >> n;
        if(n==0) break;
        layerNode * root = new layerNode;
        string path;
        for(int i=0;i<n;i++){
            cin >> path;
            buildFileTree(root, path);
        }
        printTree(root,0);
        cout << endl;
    }
    return 0;
}

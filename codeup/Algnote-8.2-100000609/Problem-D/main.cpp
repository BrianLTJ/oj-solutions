#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct boardStatus{
    int seq[8];
    int step;
    string operations;
    boardStatus() {
        step=0;
    }
};

bool foundAns=false;
string ans;

queue<string> opQueue;

int initSeq[8]={0};
int targetSeq[8]={1,2,3,4,5,6,7,8};

void cubeToSeq(int cube[][4], int seq[]){
    for(int i=0;i<4;i++)
        seq[i]=cube[0][i];

    for(int i=3;i>=0;i--)
        seq[7-i]=cube[1][i];
}

void seqToCube(int seq[], int cube[][4]){
    for(int i=0;i<4;i++)
        cube[0][i]=seq[i];
    for(int i=3;i>=0;i--)
        cube[1][i]=seq[7-i];
}


void operateCube(int oldStatus[], char opt, int newStatus[]){
    int oldCube[2][4];
    seqToCube(oldStatus,oldCube);
    switch(opt){
        case 'A':
            for(int i=0;i<4;i++){
                int temp = oldCube[0][i];
                oldCube[0][i]=oldCube[1][i];
                oldCube[1][i]=temp;
            }
            break;
        case 'B':
            for(int i=0;i<2;i++){
                int temp=oldCube[i][3];
                for(int j=3;j>0;j--){
                    oldCube[i][j]=oldCube[i][j-1];
                }
                oldCube[i][0]=temp;
            }
            break;
        case 'C':
            int temp = oldCube[0][1];
            oldCube[0][1]=oldCube[1][1];
            oldCube[1][1]=oldCube[1][2];
            oldCube[1][2]=oldCube[0][2];
            oldCube[0][2]=temp;
            break;
    }
    cubeToSeq(oldCube, newStatus);
}


/**
  * Cut Forks - 1
  * A can only appear once successionally.
  * B can appear 3 times at once.
  * C can appear 3 times at once.
 **/
 bool checkOperations(const string operations){
    if(operations.find("AA")!=string::npos) return false;
    if(operations.find("BBBB")!=string::npos) return false;
    if(operations.find("CCCC")!=string::npos) return false;
    return true;
 }

 bool cmpSeq(int seq1[], int seq2[]){
    bool ret = true;
    for(int i=0;i<8;i++)
        if(seq1[i]!=seq2[i]){
            ret = false;
            break;
        }
    return ret;
 }

void findOperation(boardStatus & status, char operation, int curStep){
    // Check if already found ans
    if(foundAns) return;

    // Check if this operation is valid
    string curOperation = status.operations + operation;
    if(!checkOperations(curOperation)) return;

    boardStatus newStatus;
    newStatus.operations = curOperation;
    memcpy(newStatus.seq, status.seq, sizeof(int)*8);

    newStatus.step = curStep+1;

    // Do the operation
    operateCube(newStatus.seq, operation, newStatus.seq);
    cout << "STEP:"<<curStep<<", curOperation:"<<curOperation<<endl;
    for(int i=0;i<8;i++)
        cout << newStatus.seq[i]<<" ";
    cout << endl;

    //Compare if target achieved
    if(cmpSeq(newStatus.seq,targetSeq)){
        // Found the solution
        foundAns = true;
        ans = curOperation;

    } else {
        // Search next step
        findOperation(newStatus, 'A', curStep+1);
        findOperation(newStatus, 'B', curStep+1);
        findOperation(newStatus, 'C', curStep+1);
    }
}

void BFSFindOperation(){
    if(opQueue.empty()) return;
    string curOp = opQueue.front();
    opQueue.pop();

    // Check curOp valid
    if(checkOperations(curOp)) {
        // curOp valid
        // Do operation
        int operatedSeq[8]={0};
        memcpy(operatedSeq,initSeq,sizeof(operatedSeq));
        for(int i=0;i<curOp.length();i++){
            operateCube(operatedSeq, curOp[i], operatedSeq);
        }
        // Check if reached Target
        if(cmpSeq(operatedSeq, targetSeq)){
            // Found Answer
            foundAns = true;
            ans = curOp;
        } else {
            // Not Found.
            opQueue.push(curOp+"A");
            opQueue.push(curOp+"B");
            opQueue.push(curOp+"C");
        }

    }

}

int main()
{
    boardStatus initBoard;
    for(int i=0;i<8;i++)
        //cin>>initBoard.seq[i];
        cin>>initSeq[i];

    /**TEST
    char opts[3]={'A','B','C'};
    for(int i=0;i<3;i++){
        cout << "Opt:"<<opts[i]<<endl;
        int newStatus[8];
        operateCube(initBoard.seq,opts[i],newStatus);
        for(int j=0;j<8;j++)
            cout << newStatus[j] << " ";
        cout << endl;
    }
    **TEST End*/

    opQueue.push("A");
    opQueue.push("B");
    opQueue.push("C");

    while(!opQueue.empty() && !foundAns){
        BFSFindOperation();
    }
    /*
    findOperation(initBoard, 'A', 0);
    findOperation(initBoard, 'B', 0);
    findOperation(initBoard, 'C', 0);
    */
    cout << ans.length() << endl;
    cout << ans;

    return 0;
}

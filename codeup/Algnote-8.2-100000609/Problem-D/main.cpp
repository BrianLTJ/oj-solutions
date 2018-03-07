#include <iostream>
#include <vector>

using namespace std;

struct boardStatus{
    int seq[8];
    int step;
    boardStatus() {
        step=0;
    }
};

vector<int> ans;

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



int main()
{
    boardStatus initBoard;
    for(int i=0;i<8;i++)
        cin>>initBoard.seq[i];

    /**TEST*/
    char opts[3]={'A','B','C'};
    for(int i=0;i<3;i++){
        cout << "Opt:"<<opts[i]<<endl;
        int newStatus[8];
        operateCube(initBoard.seq,opts[i],newStatus);
        for(int j=0;j<8;j++)
            cout << newStatus[j] << " ";
        cout << endl;
    }

    return 0;
}

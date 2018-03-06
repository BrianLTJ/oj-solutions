#include <iostream>
#include <vector>

using namespace std;

const int MAXINT = 10;
vector<vector<int>> ans;
bool curPlan[MAXINT][MAXINT]={false}; // [line][col]
int n;

bool check(int line, int col){
    for(int l=0;l<n;l++){
        //同一列
        if(curPlan[l][col])//{cout<<" ERR-0 "<<l<<","<<col<<" "; return false;}
            return false;
        //左上到右下
        if(col-line+l>=0 && col-line+l<n)
            if(curPlan[l][col-line+l])// {cout<<" ERR-1 "<<l<<","<<(col-line+l)<<" ";return false;}
                return false;
        //左下到右上
        if(col+line-l>=0 && col+line-l<n)
            if(curPlan[l][col+line-l])// {cout<<" ERR-2 "<<l<<","<<(col+line-l)<<" ";return false;}
                return false;
    }

    for(int c=0;c<n;c++)
        if(curPlan[line][c]) return false;

    return true;
}

void setChess(int curLine){
    if(curLine>=n){
        // Found Answer
        vector<int> curAns;
        for(int l=0;l<n;l++){
            for(int c=0;c<n;c++){
                if(curPlan[l][c]){
                    curAns.push_back(c+1);
                    break;
                }
            }
        }
        ans.push_back(curAns);
        return;
    }



    for(int c=0;c<n;c++){
        // clear curLine chess board
        for(int i=curLine;i<n;i++)
            for(int j=0;j<n;j++){
                //cout << "CLEAR"<<i<<","<<j<<endl;
                curPlan[i][j]=false;}

        //cout<<"["<<curLine<<","<<c<<"] ";
        if(check(curLine, c)){
            //cout<< "Success" <<endl;
            // Set Chess to [curLine,c]
            curPlan[curLine][c]=true;
            // Find next line
            setChess(curLine+1);

        }
        /*
        else {
            cout << "Fail" << endl;
        }
        */
    }
}


int main()
{
    cin>>n;
    setChess(0);
    int ansNum = ans.size();
    //cout << ansNum << endl;
    if(ansNum>0){
        // Output solutions
        for(int i=0;i<ansNum;i++){
            for(int j=0;j<n;j++){
                cout << (j>0?" ":"")<<ans[i][j];
            }

            if(i<ansNum-1) cout << endl;
        }

    } else {
        cout << "no solute!";
    }
    return 0;
}

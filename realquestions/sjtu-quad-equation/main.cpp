#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

void parseCo(const string &item, int co[]){

    int exp=0;
    double k=0.0;
    string kStr=item;

    /*** Format +x -x */
    if((kStr[0]=='+'||kStr[0]=='-')&&(kStr[1]=='x'))
        kStr=kStr.insert(1,"1");


    if(kStr.find("x^2")!=string::npos){
        exp=2;
        kStr=kStr.substr(0,kStr.find("x^2"));
    }
    else if(kStr.find("x^1")!=string::npos) {
        exp=1;
        kStr=kStr.substr(0,kStr.find("x^1"));
    }
    else if(kStr.find("x")!=string::npos) {
        exp=1;
        kStr=kStr.substr(0,kStr.find("x"));
    }

    if(kStr.length()>0){
        k=atoi(kStr.c_str());
    } else {
        k=1;
    }

    co[exp]=co[exp]+k;

}

void parse(const string & eq, int co[]){
    string temp = eq; // Use when parsing

    int lastFlag=0,i=0;
    for(i=1;i<temp.length();i++){
        if(temp[i]=='+'||temp[i]=='-'){
            // Extract item
            parseCo(temp.substr(lastFlag,i-lastFlag), co);

            //*** Update Flag
            lastFlag = i;
        }
    }
    // Extract last item
     parseCo(temp.substr(lastFlag,i-lastFlag), co);

}

int main()
{
    int co[3]={0};
    string rawEq;
    cin >>rawEq;

    string leftEq=rawEq.substr(0,rawEq.find("="));
    string rightEq=rawEq.substr(rawEq.find("=")+1);

    int coLeft[3]={0}, coRight[3]={0};

    /** Parse left equation */
    parse(leftEq, coLeft);

    /** Parse right equation */
    parse(rightEq, coRight);

    /** Merge Coefficients */
    for(int i=0;i<3;i++)
        co[i]=coLeft[i]-coRight[i];

    /** Calculate solution */

    double delta = 1.0*co[1]*co[1]-4.0*co[2]*co[0];

    if(delta<0.0){
        cout << "No Solution";
    } else {
        double x1=(-1*co[1]-sqrt(delta))/(2*co[2]);
        double x2=(-1*co[1]+sqrt(delta))/(2*co[2]);
        cout.setf(ios::fixed);
        cout << setprecision(2) << min(x1,x2) << " " << setprecision(2) << max(x1,x2);
    }
    return 0;
}

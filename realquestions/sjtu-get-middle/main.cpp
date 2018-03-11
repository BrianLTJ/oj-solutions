#include <iostream>

using namespace std;

int main()
{
    int l1, l2;
    cin >> l1 >> l2;
    int* n1 = new int[l1];
    int* n2 = new int[l2];
    for(int i=0; i < l1; i++){
        cin>>n1[i];
    }
    for(int i=0; i < l2;i++){
        cin>> n2[i];
    }
    int a,b,c,d;
    cin >> a>> b >> c >> d;
    //cout << a<<"," <<b<<","<<c<<","<<d<<endl;
    int mid = (b-a+d-c+2+1)/2;
    //cout << "MID" << b-a+c-d+2+1 << endl;
    //int curId = 1;
    if(mid>(b-a+1)){
        // mid in n2
        cout << n2[mid-(b-a+1)+c-1-1] << endl;
    } else {
        cout << n1[mid-1+a-1] << endl;
    }
    return 0;
}

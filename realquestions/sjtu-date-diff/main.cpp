#include <iostream>
#include <cmath>

using namespace std;
int dayInMonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

struct date{
    int year;
    int month;
    int day;
    date(){
        year=0;
        month=1;
        day=1;
    }
    date(int _year, int _month, int _day){
        year = _year;
        month = _month;
        day = _day;
    }
};

date base(0,1,1);

bool isLeap(int year){
    return (year%100!=0 && year%4==0)||(year%400==0);
}

int getDelta(date &d) {
    int deltaDays = 0;
    int baseY=base.year;
    for(baseY=base.year;baseY<d.year;baseY++){
        deltaDays+=(isLeap(baseY)?366:365);
    }
    int baseM=base.month;
    for(baseM=base.month;baseM<d.month;baseM++){
        if(baseM!=2)
            deltaDays+=dayInMonth[baseM];
        else
            deltaDays+=(dayInMonth[baseM]+isLeap(baseY));
    }
    deltaDays+=(d.day-1);
    //cout << "Delta:" << deltaDays<<endl;
    return deltaDays;
}

int getDiff(date &d1, date&d2){
    base.year = min(d1.year, d2.year);
    return abs(getDelta(d1)-getDelta(d2))+1;
}

int main()
{
    int dn1, dn2;
    while(cin>>dn1>>dn2){
        if(dn1>dn2){
            int temp=dn1;
            dn1=dn2;
            dn2=temp;
        }
        date d1(dn1/10000,(dn1/100)%100, dn1%100);
        date d2(dn2/10000,(dn2/100)%100, dn2%100);
        cout << getDiff(d1, d2) << endl;
    }

    return 0;
}

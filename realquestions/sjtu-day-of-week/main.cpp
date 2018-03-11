#include <iostream>
#include <cstring>
#include <map>

using namespace std;

struct Day{
    int year;
    int month;
    int date;
    int dayOfWeek;
    Day(){
        year = 0;
        month = 0;
        date = 0;
        dayOfWeek = -1;
    };
    Day(int _year, int _month, int _date){
        year = _year;
        month = _month;
        date = _date;
        dayOfWeek = -1;
    };
    Day(int _year, int _month, int _date, int _dayOfWeek){
        year = _year;
        month = _month;
        date = _date;
        dayOfWeek = _dayOfWeek;
    };
};
int getDeltaDayToStart(Day);
bool leapYear(int);

map<string,int> monthToNum;
map<string, int> weekDayToDay;
string months[13]={"x","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
string dayofweek[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int monthDates[13][2]={{0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}};

Day base(2018,3,11,0);
Day startDay(1000, 1, 1);

void initMapsArrays(){
    // Init monthToNum
    for(int i=1;i<13;i++){
        monthToNum[months[i]]=i;
    }
    for(int i=0;i<7;i++){
        weekDayToDay[dayofweek[i]]=i;
    }

    // Set startDay weekday
    int deltaDays = getDeltaDayToStart(base);
    startDay.dayOfWeek=(7-(deltaDays%7))%7;

}

bool leapYear(int year){
    return (year%400==0)||(year%100!=0&&year%4==0);
}


int getDeltaDayToStart(Day d){
    int y=startDay.year, m;
    int deltaDays=0;
    for(y=startDay.year;y<d.year;y++){
        deltaDays+=leapYear(y)?366:365;
    }
    for(m=startDay.month;m<d.month;m++){
        if(m!=2){
            deltaDays+=monthDates[m][0];
        } else {
            deltaDays+=monthDates[m][(leapYear(y)?1:0)];
        }
    }
    deltaDays+=(d.date-startDay.date);
    return deltaDays;
}

/** Get Date Number
 ** yyyymmdd
**/
int getDateNum(int year, int month, int day){
    return year*10000+month*100+day;
}

int getDayofWeek(Day &d){
    int deltaDay = getDeltaDayToStart(d);

    return (startDay.dayOfWeek+deltaDay%7)%7;
}

int main()
{
    int date, year;
    string month;
    initMapsArrays();
    while(cin>>date>>month>>year){
        Day d(year,monthToNum[month],date);
        cout << dayofweek[getDayofWeek(d)] << endl;
    }

    return 0;
}

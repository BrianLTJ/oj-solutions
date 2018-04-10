#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int num = 0, openTime = 86400, closeTime = 0;
    char openPerson[20]={'\0'}, closePerson[20]={'\0'};
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        int inTime = 0, outTime = 86400;
        int inH = 0, inM = 0, inS = 0;
        int outH = 0, outM = 0, outS = 0;
        char name[20];
        scanf("%s", name);
        //printf("NAME: %s\n",name);
        scanf("%2d:%2d:%2d", &inH, &inM, &inS);
        //printf("INTIME: %02d:%02d:%02d\n", inH, inM, inS);
        scanf("%2d:%2d:%2d", &outH, &outM, &outS);
        //printf("OUTTIME: %02d:%02d:%02d\n", outH, outM, outS);
        inTime = inH * 3600 + inM * 60 + inS;
        //printf("INTIME: %d\n", inTime);
        if(inTime < openTime){
            openTime = inTime;
            strcpy(openPerson, name);
        }
        outTime = outH * 3600 + outM * 60 + outS;
        //printf("OUTTIME: %d", outTime);
        if(outTime > closeTime){
            closeTime = outTime;
            strcpy(closePerson, name);
        }
    }
    //printf("%d %d\n", openTime, closeTime);
    printf("%s %s", openPerson, closePerson);
    return 0;
}

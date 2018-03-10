#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct bigInt;

const int MAXLEN = 800;


void bAdd(const bigInt&, const bigInt&, bigInt&);

void bMinus(const bigInt&, const bigInt&, bigInt&);

void bMul(const bigInt&, const bigInt&, bigInt&);

void alignLeft(bigInt&);

// ABS
// 1: a>b
// 0: a==b
// -1: a<b
int cmpBigIntAbs(const bigInt&, const bigInt&);

struct bigInt{
    char num[MAXLEN];
    bool positive;
    int len;
    bigInt(){
        fill(num,num+MAXLEN,'0');
        positive = true;
        len = 0;
    }
    void printInt(){
        if(len==0||(len==1&&num[0]=='0')){
            printf("0");
            return;
        }

        if(!positive){
            printf("-");
        }
        printf("%s", num);
    }
    void updateLen(){
        len = strlen(num);
    }
};

int cmpBigIntAbs(const bigInt & a, const bigInt & b){
    if(a.len!= b.len){
        return (a.len>b.len?1:-1);
    }
    int boundary = a.len;
    for(int i=0;i<boundary;i++){
        if(a.num[i]!=b.num[i]){
            return (a.num[i]-b.num[i]>0?1:-1);
        }
    }
    return 0;
}

void bAdd(const bigInt & a, const bigInt & b, bigInt & result){
    int carry = 0;
    bigInt aN, bN;
    memcpy(aN.num, a.num, sizeof(aN.num));
    memcpy(bN.num, b.num, sizeof(bN.num));
    aN.positive = a.positive;
    bN.positive = b.positive;
    aN.len = a.len;
    bN.len = b.len;
    if(a.positive && !b.positive){
        // a+(-|b|)=>a-|b|
        bN.positive = true;
        bMinus(aN, bN, result);
        return;
    } else if(!a.positive && b.positive){
        // a negative b positive
        // (-|a|)+b => b-|a|
        aN.positive = true;
        bMinus(bN, aN, result);
        return;
    } else if(!a.positive && !b.positive) {
        // a negative b negative
        // (-|a|)+(-|b|) => -(|a|+|b|)<0
        result.positive = false;
        aN.positive = true;
        bN.positive = true;
    }
    // Do Not Change Positive status
    int anum=0,bnum=0;
    int boundary=max(strlen(aN.num), strlen(bN.num));
    int resultMaxLen = boundary+1;
    for(int i=0; i<=boundary;i++){
        anum = (i>=aN.len?0:aN.num[aN.len-1-i]-'0');
        bnum = (i>=bN.len?0:bN.num[bN.len-1-i]-'0');
        int rnum = anum+bnum+carry;
        carry = rnum/10;
        result.num[resultMaxLen-i-1]='0'+(rnum%10);
    }
    result.num[resultMaxLen]='\0';
    alignLeft(result);
}

void bMinus(const bigInt & a, const bigInt & b, bigInt & result) {
    bigInt aN, bN;
    memcpy(aN.num, a.num, sizeof(aN.num));
    memcpy(bN.num, b.num, sizeof(bN.num));
    aN.positive = a.positive;
    bN.positive = b.positive;
    aN.len = a.len;
    bN.len = b.len;
    if(a.positive && !b.positive){
        // a-(-|b|)=>a+|b|
        bN.positive = true;
        bAdd(aN, bN, result);
        return;
    } else if(!a.positive && b.positive){
        // a negative b positive
        // (-|a|)-b => (-|a|)+(-|b|)
        bN.positive = false;
        bAdd(aN, bN, result);
        return;
    } else if(!a.positive && !b.positive) {
        // a negative b negative
        // (-|a|)-(-|b|) => -(|a|)+|b| => |b|-|a|
        aN.positive = true;
        bN.positive = true;
        bMinus(bN, aN, result);
        return;
    }

    if(cmpBigIntAbs(aN,bN)<0){
        bMinus(b,a,result);
        result.positive=false;
        return;
    }


    // a - b, a>b>0
    int borrow=0; // always >=0
    int anum=0,bnum=0;
    int boundary=max(strlen(aN.num), strlen(bN.num));
    int resultMaxLen = boundary;
    for(int i=0;i<=boundary;i++){
        anum = (i>=aN.len?0:aN.num[aN.len-1-i]-'0')-borrow;
        bnum = (i>=bN.len?0:bN.num[bN.len-1-i]-'0');
        //printf("%d - %d, borrow:%d\n", anum, bnum, borrow);
        if(anum-bnum<0){
            anum+=10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        int rnum=anum-bnum;
        result.num[resultMaxLen-i-1]='0'+rnum;
    }

    result.num[resultMaxLen]='\0';
    alignLeft(result);
    //alignLeft(result);
}

void bMul(const bigInt & a, const bigInt & b, bigInt & result){
    if(cmpBigIntAbs(a,b)<0){
        bMul(b,a,result);
        return;
    }

    bigInt aN, bN;
    memcpy(aN.num, a.num, sizeof(aN.num));
    memcpy(bN.num, b.num, sizeof(bN.num));
    aN.positive = true;
    bN.positive = true;
    aN.len = a.len;
    bN.len = b.len;
    result.num[0]='0';
    result.num[1]='\0';
    result.updateLen();

    int loopTime =b.len;
    int maxLen = a.len;
    int resMaxLen = maxLen+1;
    int carry = 0;
    int anum, bnum;

    for(int i=0;i<loopTime;i++){
            // i also as fill in 0 numbers
        bigInt curRes;
        bnum = bN.num[bN.len-1-i]-'0';
        for(int j=0;j<a.len;j++){
            anum = aN.num[aN.len-1-j]-'0';
            int rnum = anum*bnum+carry;
            curRes.num[resMaxLen-j-1]='0'+rnum%10;
            carry = rnum/10;
        }
        curRes.num[0]='0'+carry;
        carry=0;
        for(int j=0;j<i;j++){
            // * 10^i
            curRes.num[resMaxLen+j]='0';
        }
        curRes.num[resMaxLen+i]='\0';
        alignLeft(curRes);
        /*printf("Add to result:");
        curRes.printInt();
        printf("\n");*/
        bAdd(result, curRes, result);
    }

    result.positive = a.positive | b.positive;
    alignLeft(result);
}

void alignLeft(bigInt &a){
    // Align to left
    int i=0;
    while(a.num[i]=='0' && a.num[i]!='\0')
        i++;

    int s=0;
    if(i>0){
        while(a.num[i]!='\0'){
            a.num[s]=a.num[i];
            s++;i++;
        }

        // DO NOT FORGET THE ENDING \0
        a.num[s]='\0';

    }
    if(a.num[0]=='\0'){
        a.num[0]='0';
        a.num[1]='\0';
    }
    // Update a.len
    a.updateLen();
}


int main()
{
    bigInt a[2];
    char tempNum[MAXLEN+1];
    for(int i=0;i<2;i++){
        scanf("%s",tempNum);
        if(tempNum[0]=='-'){
            a[i].positive = false;
            tempNum[0]='0';
        } else if(tempNum[0]<'0' || tempNum[0]>'9'){
            a[i].positive = true;
            tempNum[0]='0';

        }
        // Input to a
        int s=0;
        // filter out first Zeros
        while(tempNum[s]=='0')
            s++;

        int j=0;
        while(tempNum[s]!='\0'){
            a[i].num[j]=tempNum[s];
            j++;s++;
        }
        a[i].num[j]='\0';
        a[i].updateLen();
    }

    bigInt addRes;
    bAdd(a[0], a[1], addRes);
    addRes.printInt();
    printf("\n");
    bigInt minusRes;
    bMinus(a[0], a[1], minusRes);
    minusRes.printInt();
    printf("\n");
    bigInt mulRes;
    bMul(a[0], a[1], mulRes);
    mulRes.printInt();


    return 0;
}

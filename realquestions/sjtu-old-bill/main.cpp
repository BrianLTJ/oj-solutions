#include <cstdio>

using namespace std;
bool check(int n,int dig1, int x, int y,int z, int dig2){
    int totalPrice = dig1*10000+x*1000+y*100+z*10+dig2;
    //printf("Price %d, mod n:%d, ok?:%d\n",totalPrice,totalPrice%n,totalPrice%n==0);
    return totalPrice%n==0;
}
void findPrice(int n, int x, int y, int z){
    // $ dig1 x y z dig2
    int dig1,dig2;
    // if n is even, just search even dig2
    int dig2Step = (n&1==0?2:1);
    bool found=false;
    for(dig1=9;dig1>0;dig1--){
        for(dig2=(n&1==0?8:9);dig2>=0;dig2=dig2-dig2Step){
            if(check(n,dig1,x,y,z,dig2)){
                found = true;
                break;
            }
        }
        if(found) break;
    }

    if(found){
        printf("%d %d %d\n",dig1,dig2,(dig1*10000+x*1000+y*100+z*10+dig2)/n);
    } else {
        printf("0\n");
    }
}

int main()
{
    int n,x,y,z;
    while(scanf("%d%d%d%d",&n,&x,&y,&z)!=EOF){
        findPrice(n,x,y,z);
    }
    return 0;
}

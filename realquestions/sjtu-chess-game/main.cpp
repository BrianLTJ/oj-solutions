#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

struct coord{
    int line;
    int col;
    int status;
    coord(){
        line = -1;
        col = -1;
        status = 1;
    }
    coord(int l, int c){
        line = l;
        col = c;
    }
    coord(int l, int c, int s){
        line = l;
        col = c;
        status = s;
    }
};
const int MAXN = 6;
const int INF = 100000;
int chessCost[6][6]={0};
int curMinCost[6][6];
int curMinStatus[6][6];

coord startp, endp;

queue<coord> bfs;

bool cmpCoord(coord p1, coord p2){
    return (p1.line==p2.line) && (p1.col == p2.col);
}

/** Check move in direction
 ** 0: up
 ** 1: right
 ** 2: down
 ** 3: left
**/

bool checkAvail(coord & p){
    return (p.line>=0) && (p.line < MAXN) && (p.col>=0) && (p.col <MAXN);
}

bool checkMove(coord & p, int direction){
    switch(direction){
        case 0:
            return (p.line>0) && (p.line < MAXN);
            break;
        case 1:
            return (p.col>=0) && (p.col < (MAXN-1));
            break;
        case 2:
            return (p.line>=0) && (p.line < (MAXN-1));
            break;
        case 3:
            return (p.col>0) && (p.col <MAXN);
            break;
    }
    return false;
}

/** Status uncalculated */
void getMoveCoord(coord &startp, coord &newCoord, int direction){
    if(!checkMove(startp,direction)) return;
    newCoord.line = startp.line;
    newCoord.col = startp.col;
    switch(direction){
        case 0:
            newCoord.line=startp.line-1;
            break;
        case 1:
            newCoord.col=startp.col+1;
            break;
        case 2:
            newCoord.line=startp.line+1;
            break;
        case 3:
            newCoord.col=startp.col-1;
            break;
    }
}

int getMoveCost(coord & startp, int direction){
    if(!checkMove(startp,direction)) return 0;
    coord newCoord;
    getMoveCoord(startp,newCoord, direction);
    return startp.status*chessCost[newCoord.line][newCoord.col];

}

int getNewStatus(coord & startp, int direction){
    return (getMoveCost(startp, direction)%4)+1;
}

void moveCoord(coord & startp, coord & endp,int direction){
    if(!checkMove(startp, direction)) return;
    // Move Coordinate
    getMoveCoord(startp, endp, direction);

    // Calc new status
    endp.status = getNewStatus(startp, direction);
}

int main()
{
    // Input chess cost
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
            scanf("%d", &chessCost[i][j]);

    scanf("%d%d%d%d", &startp.line, &startp.col,&endp.line,&endp.col);

    bool found=false;

    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            curMinCost[i][j]=INF;
            curMinStatus[i][j]=INF;
        }
    }

    curMinCost[startp.line][startp.col]=0;
    startp.status = 1;
    bfs.push(startp);

    while(!bfs.empty()){
        coord curP(bfs.front().line, bfs.front().col, bfs.front().status);
        //printf("Now Proc %d %d [Status:%d]. \n", curP.line, curP.col, curP.status);
        // Traverse 4 directions
        for(int d=0; d<4;d++){
            if(checkMove(curP, d)){
                // OK to move
                coord newP;
                moveCoord(curP,newP,d);
                //printf("New Move(%d) %d %d [Status:%d]. MoveCost: %d. curP:curMinCost: %d, moved P curMinCost: %d \n", d, newP.line, newP.col, newP.status, getMoveCost(curP, d), curMinCost[curP.line][curP.col],curMinCost[newP.line][newP.col]);
                // Check cost
                if(getMoveCost(curP, d)+curMinCost[curP.line][curP.col]<=curMinCost[newP.line][newP.col]){
                    curMinCost[newP.line][newP.col]=getMoveCost(curP, d)+curMinCost[curP.line][curP.col];
                    // Add new coord to queue
                    bfs.push(newP);
                    //printf("Push %d %d [Status:%d] to queue. \n", newP.line, newP.col, newP.status);
                }
            }
        }
        bfs.pop();
    }
    /***TEST*/
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            printf("%9d ", curMinCost[i][j]);
        }
        printf("\n");
    }
    printf("%d", curMinCost[endp.line][endp.col]);

    return 0;
}

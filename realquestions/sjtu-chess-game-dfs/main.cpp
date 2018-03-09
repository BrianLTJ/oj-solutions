#include <cstdio>

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
        status = 1;
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
int curMinCostToEnd = INF;

coord startp, endp;

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

/**fromDirection: Last Level go direction*/
void dfs(coord & curP, int curCost, int fromDirection){
    //printf("DFS Search [%3d,%3d]\n", curP.line, curP.col);
    if(!checkAvail(curP)) return;
    if(curCost>curMinCostToEnd) return;

    if(cmpCoord(curP, endp)){
        if(curCost<curMinCostToEnd){
            curMinCostToEnd = curCost;
            return;
        }
    }

    // Havent reach end
    for(int d=0;d<4;d++){
        // Prevent go back to last p
        if((d==(fromDirection+2)%4) && fromDirection>-1) continue;

        coord newP;

        if(!checkMove(curP, d)) continue;

        moveCoord(curP,newP, d);

        int newCost = curCost+getMoveCost(curP, d);

        if(newCost>=curMinCostToEnd){
            // current cost larger than currentMinCost
            // Abandon search in this direction
            continue;
        } else {
            // Continue to search
            dfs(newP, newCost, d);
        }
    }


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

    dfs(startp, 0, -1);

    printf("%d", curMinCostToEnd);
    return 0;
}

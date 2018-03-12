#include <cstdio>
#include <algorithm>

using namespace std;
const int MAXCITY = 500;
const int INF = 100000000;

int main(){
    int N, M, C1, C2;
    scanf("%d%d%d%d", &N, &M, &C1, &C2);
    int weight[MAXCITY];
    for(int i=0; i < N; i++){
        scanf("%d", &weight[i]);
    }
    int G[MAXCITY][MAXCITY];
    fill(G[0],G[0]+MAXCITY*MAXCITY, INF);
    int u, v;
    for(int i = 0; i<M; i++){
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u]=G[u][v];
    }
    // 节点是否已经找到最短路径
    bool visited[MAXCITY];
    fill(visited, visited+MAXCITY, false);

    // 到达该城市的最短路径中，经过节点权重之和最大的
    int w[MAXCITY]={0};
    fill(w, w + MAXCITY, 0);
    w[C1]=weight[C1];

    // 到目前为止，到达该城市已探明的最短距离
    int d[MAXCITY];
    fill(d, d + MAXCITY, INF);
    d[C1] = 0;

    // 到达城市i的最短路径数量
    int num[MAXCITY] = {0};
    num[C1] = 1;

    /// Dijkstra
    for(int i=0; i<N; i++){
        /// Get the nearest city
        int c=-1, minDst = INF;
        for(int j=0; j<N; j++){
            if(!visited[j] && d[j] < minDst) {
                /// Update c, minDst
                c = j;
                minDst = d[j];
            }
        }
        /// Remaining cities don't connect
        if(c==-1) break;

        visited[c] = true;

        /// Update d[city]
        for(int v=0; v < N; v++){
            /// city v hasnt visited, c-v connected
            if(!visited[v] && G[c][v] < INF){
                if(d[c] + G[c][v] < d[v]) {
                    /// C1-c-v is shorter
                    /// Update d
                    d[v] = d[c] + G[c][v];
                    /// Update num
                    num[v] = num[c];
                    /// Update w
                    w[v] = w[c] + weight[v];
                } else if(d[c] + G[c][v] == d[v]){
                    /// Found another short path
                    /// Update num
                    num[v] += num[c];

                    /// Try to update w
                    if(w[c] + weight[v] > w[v]) {
                        w[v] = weight[v] + w[c];
                    }
                }

            }

        }

    } /// End Dijkstra

    printf("%d %d", num[C2], w[C2]);



    return 0;
}

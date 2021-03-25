//# Author : nuclear852 ========================#
//# Solution : 22809659 ========================#
//# Time Stamp : 2020-09-24 22:56:33 ===========#
//# Problem Title : 격자 0 만들기 ===============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#define INF 0x7FFFFFFF
using namespace std;


const int S = 0, E = 2609;
int arr[52][52];
int index[52][52];
vector<int> adj[2610];
//bool pos[2610];
int checked[2610];

int c[2610][2610];
int f[2610][2610];

// map< pair<int, int>, int> c;
// map< pair<int, int>, int> f;
int lv[2610];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool bfs() {
    queue<int> q;
    for(int i=S; i<=E; i++) lv[i] = -5;
    lv[S] = 0;
    q.push(S);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto next: adj[cur]) {
            if(lv[next] == -5 && c[cur][next] - f[cur][next] > 0) {
                lv[next] = lv[cur] + 1;
                q.push(next);
            }
        }
    }
    return lv[E] != -5;
}

int dfs(int cur, int flow) {
    if(cur == E) return flow;
    //if(!pos[cur]) return pos[cur];
    int cur_flow = 0;
    //for(auto next: adj[cur]) {
    for(int &i = checked[cur]; i < adj[cur].size(); i++){
        int next = adj[cur][i];
        //if(!pos[next]) continue;
        if(lv[next] == lv[cur] + 1 && c[cur][next] - f[cur][next] > 0) {
            cur_flow = dfs(next, min(flow, c[cur][next] - f[cur][next]));
            if(cur_flow) {
                f[cur][next] += cur_flow;
                f[next][cur] -= cur_flow;
                return cur_flow;
            }
        }
    }
    return 0;
    //return pos[cur] = 0;
}


int T, n, m;
int main() {
    scanf("%d", &T);
    while(T--) {
        for(int i=0; i<2610; i++) {
            adj[i].clear();
            lv[i] = -1;
        }
        for(int i=0; i<2610; i++) {
            for(int j=0; j<2610; j++) {
                c[i][j] = f[i][j] = 0;
            }
        }
        scanf("%d%d", &n, &m);
        int left_index = 1, right_index = 1301;
        long long sum = 0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                scanf("%d", &arr[i][j]);
                sum += (long long)arr[i][j];
                if((i+j) % 2 == 0) {
                    index[i][j] = left_index++;
                }
                else {
                    index[i][j] = right_index++;
                }
            }
        }

        
        // for(int i=1; i<=n; i++) {
        //     for(int j=1; j<=m; j++) {
        //         printf("%d ", index[i][j]);
        //     }
        //     printf("\n");
        // }

                
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if( (i+j) % 2 == 0 ) {
                    adj[S].push_back(index[i][j]);
                    adj[index[i][j]].push_back(S);
                    c[S][index[i][j]] = arr[i][j];
                    for(int k=0; k<4; k++) {
                        if(i+dx[k] <= 0 || i+dx[k] > n || j+dy[k] <= 0 || j+dy[k] > m) continue;
                        adj[index[i][j]].push_back(index[i+dx[k]][j+dy[k]]);
                        adj[index[i+dx[k]][j+dy[k]]].push_back(index[i][j]);
                        c[index[i][j]][index[i+dx[k]][j+dy[k]]] = INF;
                    }
                }
                else {
                    adj[index[i][j]].push_back(E);
                    adj[E].push_back(index[i][j]);
                    c[index[i][j]][E] = arr[i][j];
                }
            }
        }

        long long flow = 0;
        while(bfs()) {
            //for(int i=S; i<=E; i++) pos[i] = 1;
            for(int i=S; i<=E; i++) checked[i] = 0;
            while(1){
                int cur_flow = dfs(S, INF);
                if(!cur_flow) break;
                flow += (long long)cur_flow;
            }
        }

        printf("%lld\n", sum - flow);

    }
}
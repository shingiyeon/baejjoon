//# Author : nuclear852 ========================#
//# Solution : 23716819 ========================#
//# Time Stamp : 2020-11-07 23:41:16 ===========#
//# Problem Title : 파티 =====================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 999999999
using namespace std;

int N, K, D;

int level[330];
int c[330][330];
int f[330][330];
int checked[330];
vector<int> adj[330];

const int S = 0, E = 329;

bool bfs() {
    queue<int> q; 
    for(int i=S; i<=E; i++) level[i] = -5;
    q.push(S);
    level[S] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto next: adj[cur]) {
            if(level[next] == -5 && c[cur][next] > f[cur][next]) {
                level[next] = level[cur] + 1;
                q.push(next);
            }
        }
    }
    return level[E] != -5;
}

int dfs(int cur, int before_flow) {
    if(cur == E) return before_flow;

    for(int &i = checked[cur]; i < adj[cur].size(); i++) {
        int next = adj[cur][i];
        if(level[next] == level[cur] + 1 && c[cur][next] > f[cur][next]) {
            int flow = dfs(next, min(before_flow, c[cur][next]-f[cur][next]));
            if(flow) {
                f[cur][next] += flow;
                f[next][cur] -= flow;
                return flow;
            } 
        }
    }
    return 0;
}

int main() {
    scanf("%d%d%d", &N, &K, &D);
    int tmp, Z;
    for(int i=1; i<=D; i++) {
        scanf("%d", &tmp);
        adj[200+i].push_back(E);
        adj[E].push_back(200+i);
        c[200+i][E] = tmp;
    }
    for(int i=1; i<=N; i++) {
        scanf("%d", &Z);
        adj[S].push_back(i);
        adj[i].push_back(S);
        c[S][i] = K;
        for(int j=1; j<=Z; j++) {
            scanf("%d", &tmp);
            adj[i].push_back(200+tmp);
            adj[200+tmp].push_back(i);
            c[i][200+tmp] = 1;
        }
    }
    int total_flow = 0;
    while(bfs()) {
        for(int i=S; i<=E; i++) {
            checked[i] = 0;
        }
        while(true) {
            int cur_flow = dfs(S, INF);
            // printf("%d\n", cur_flow);
            if(!cur_flow) break;
            total_flow += cur_flow;
        }
    }

    printf("%d", total_flow);

}
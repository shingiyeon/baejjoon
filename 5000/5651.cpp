//# Author : nuclear852 ========================#
//# Solution : 23677439 ========================#
//# Time Stamp : 2020-11-05 23:05:30 ===========#
//# Problem Title : 완전 중요한 간선 ==============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int K, N, M;

int c[330][330];
int f[330][330];
vector<pair<int, int> > edge;
vector<int> adj[330];

int level[330];
int checked[330];
bool visited[330];
int S = 1, E;

int bfs(int start, int dest) {
    queue<int> q;
    for(int i=S; i<=E; i++) {
        level[i] = -5;
    }
    level[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto next: adj[cur]) {
            if(c[cur][next] - f[cur][next] > 0 && level[next] == -5) {
                level[next] = level[cur] + 1;
                q.push(next);
            }
        }
    }
    return level[dest] != -5;
}

int dfs(int cur, int dest, int before_flow) {
    int cur_flow = 0;
    if(cur == dest) return before_flow;

    for(auto &i = checked[cur]; i < adj[cur].size(); i++) {
        int next = adj[cur][i];
        if(level[next] == level[cur] + 1 && c[cur][next] - f[cur][next] > 0) {
            cur_flow = dfs(next, dest, min(before_flow, c[cur][next] - f[cur][next]));
            if(cur_flow) {
                f[cur][next] += cur_flow;
                f[next][cur] -= cur_flow;
                return cur_flow;
            }
        }
    }
    return 0;
}

bool cdfs(int cur, int dest) {
    if(cur == dest) return true;
    visited[cur] = 1;
    for(auto next : adj[cur]) {
        if(visited[next] == 0 && c[cur][next] - f[cur][next] > 0) {
            if(cdfs(next, dest)) return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &K);
    while(K--) {
        int ans = 0;
        for(int i=0; i<330; i++) {
            for(int j=0; j<330; j++) {
                c[i][j] = 0; f[i][j]=0;
            }
            adj[i].clear();
        }
        edge.clear();

        scanf("%d%d", &N, &M);
        E = N;
        int f, t, b;
        for(int i=1; i<=M; i++) {
            scanf("%d%d%d", &f, &t, &b);
            c[f][t] += b;
            adj[f].push_back(t);
            adj[t].push_back(f);
            edge.push_back({f, t});
        }

        while(bfs(S, E)) {
            for(int i=S; i<=E; i++) checked[i] = 0;
            while(1) {
                int flow = dfs(S, E, 999999999);
                if(flow == 0) break;
            }
        }

        for(auto p : edge) {
            for(int i=S; i<=E; i++) visited[i] = 0;
            if(cdfs(p.first, p.second) == 0) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}
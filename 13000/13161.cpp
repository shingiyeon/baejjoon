//# Author : nuclear852 ========================#
//# Solution : 23699183 ========================#
//# Time Stamp : 2020-11-06 23:39:10 ===========#
//# Problem Title : 분단의 슬픔 =================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>
#define INF 999999999
using namespace std;

int N;
vector<int> adj[505];
int c[505][505];
int f[505][505];

int level[505];
int checked[505];
bool visited[505];
const int S = 0, E = 504;

bool bfs() {
    for(int i=S; i<=E; i++) {
        level[i] = -5;
    }
    queue<int> q;
    q.push(S);
    level[S] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto next: adj[cur]) {
            if(level[next] == -5 && c[cur][next] - f[cur][next] > 0) {
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
        if(level[next] == level[cur] + 1 && c[cur][next] - f[cur][next] > 0) {
            int cur_flow = dfs(next, min(c[cur][next] - f[cur][next], before_flow));
            if(cur_flow) {
                f[cur][next] += cur_flow;
                f[next][cur] -= cur_flow;
                return cur_flow;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d", &N);
    int t;
    for(int i=1; i<=N; i++) {
        scanf("%d", &t);
        if(t == 1) {
            adj[S].push_back(i);
            adj[i].push_back(S);
            c[S][i] = INF;
        }
        else if(t == 2) {
            adj[E].push_back(i);
            adj[i].push_back(E);
            c[i][E] = INF;
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d", &t);
            if(i==j) continue;
            adj[i].push_back(j);
            c[i][j] = t;
        }
    }

    int total_flow = 0;
    while(bfs()) {
        for(int i=S; i<=E; i++) checked[i] = 0;
        while(true) {
            int flow = dfs(S, INF);
            if(!flow) break;
            total_flow += flow;
        }
    }

    queue<int> q;
    q.push(S);
    visited[S] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int next: adj[cur]) {
            if(visited[next] == 0 && c[cur][next] > f[cur][next]) {
                visited[next] = 1;
                q.push(next);
            }
        }
    }

    printf("%d\n", total_flow);
    for(int i=1; i<=N; i++) {
        if(visited[i]) printf("%d ", i);
    }
    printf("\n");
    for(int i=1; i<=N; i++) {
        if(!visited[i]) printf("%d ", i);
    }
    printf("\n");
}
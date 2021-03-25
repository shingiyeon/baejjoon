//# Author : nuclear852 ========================#
//# Solution : 24157418 ========================#
//# Time Stamp : 2020-12-01 23:46:58 ===========#
//# Problem Title : 동전 교환 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int T, n, m;

queue<int> q;
bool inQ[1002];
int parent[1002];
int dist[1002];

vector<int> adj[1002];
int c[1002][1002];
int f[1002][1002];
int d[1002][1002];

const int S = 0, E = 1001;

pair<int, int> SPFA() {
    int cost = 0, flow = 0;
    while(1) {
        for(int i=S; i<=E; i++) {
            dist[i] = 999999999;
            parent[i] = -1;
            inQ[i] = 0;
        }

        queue<int> q;
        q.push(S);
        inQ[S] = 1;
        dist[S] = 0;

        while(!q.empty()) {
            int cur = q.front(); q.pop();
            inQ[cur] = 0;
            for(auto next: adj[cur]) {
                //printf("%d\n", next);
                if(c[cur][next] > f[cur][next] && dist[next] > dist[cur] + d[cur][next]) {
                    dist[next] = dist[cur] + d[cur][next];
                    parent[next] = cur;
                    if(!inQ[next]) {
                        q.push(next);
                        inQ[next] = 1;
                    }
                }
            }
        }

        //printf("%d\n", parent[E]);
        if(parent[E] == -1) break;
        int cur_flow = 999999999;
        for(int i=E; i!=S; i=parent[i]) {
            cur_flow = min(cur_flow, c[parent[i]][i] - f[parent[i]][i]);
        }
        flow += cur_flow;
        for(int i=E; i!=S; i=parent[i]) {
            cost += d[parent[i]][i] * cur_flow;
            f[parent[i]][i] += cur_flow;
            f[i][parent[i]] -= cur_flow;
        }
    }
    return {flow, cost};
}

int main() {
    scanf("%d", &T);
    while(T--) {
        for(int i=S; i<=E; i++) {
            adj[i].clear();
            for(int j=S; j<=E; j++) {
                c[i][j] = f[i][j] = d[i][j] = 0;
            }
        }
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; i++) {
            adj[i].push_back(i+500);
            adj[i+500].push_back(i);
            c[i][i+500] = 999999999;
            c[i+500][i] = 999999999;
        }

        for(int i=1; i<=m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].push_back(500+b);
            adj[500+b].push_back(a);
            adj[b].push_back(500+a);
            adj[500+a].push_back(b);
            c[a][500+b] = 999999999; 
            c[b][500+a] = 999999999;
            d[a][500+b] = 1; d[500+b][a] = -1;
            d[b][500+a] = 1; d[500+a][b] = -1;
        }

        for(int i=1; i<=n; i++) {
            int tmp; scanf("%d", &tmp);
            if(tmp) {
                adj[S].push_back(i);
                adj[i].push_back(S);
                c[S][i] = 1;
            }
        }
        for(int i=1; i<=n; i++) {
            int tmp; scanf("%d", &tmp);
            if(tmp) {
                adj[E].push_back(500+i);
                adj[500+i].push_back(E);
                c[500+i][E] = 1;
            }
        }
        printf("%d\n", SPFA().second);
    }
}
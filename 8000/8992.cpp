//# Author : nuclear852 ========================#
//# Solution : 24139369 ========================#
//# Time Stamp : 2020-11-30 23:29:04 ===========#
//# Problem Title : 집기 게임 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#define MAX 1999999999
using namespace std;

int T;

int c[405][405];
int f[405][405];
int d[405][405];

int parent[405];
int dist[405];
bool inQ[405];

struct Garo {
    int x1, x2, y, w;
}Ga[201];
struct Sero {
    int x, y1, y2, w;
}Se[201];

vector<int> adj[405];
const int S = 0, E = 404;

pair<int, int> SPFA() {
    int flow = 0, cost = 0;

    while(1) {
        for(int i=S; i<=E; i++) {
            parent[i] = -1;
            inQ[i] = 0;
            dist[i] = MAX;
        }

        queue<int> q;
        q.push(S);
        inQ[S] = 1;
        dist[S] = 0;

        while(!q.empty()) {
            int cur = q.front(); q.pop(); inQ[cur] = 0;
            for(auto next: adj[cur]) {
                if(c[cur][next] > f[cur][next] && dist[cur] + d[cur][next] < dist[next]) {
                    dist[next] = dist[cur] + d[cur][next];
                    parent[next] = cur;
                    if(!inQ[next]) {
                        q.push(next);
                        inQ[next] = 1;
                    }
                }
            }
        }

        if(parent[E] == -1) break;
        int cur_flow = MAX;
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
    int n, m;
    int x1, x2, y1, y2, w;
    scanf("%d", &T);
    while(T--) {
        int G_idx = 0;
        int S_idx = 0;
        for(int i=0; i<405; i++) {
            for(int j=0; j<405; j++) {
                f[i][j] = c[i][j] = d[i][j] = 0;
            }
            adj[i].clear();
        }
        scanf("%d%d", &n, &m);
        for(int i=0; i<n+m; i++) {
            scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &w);
            if(y1 == y2) {
                if(x1 > x2) {
                    int tmp = x1; x1 = x2; x2 = tmp;
                }
                Ga[G_idx].x1 = x1; Ga[G_idx].x2 = x2;
                Ga[G_idx].y = y1; Ga[G_idx].w = w; G_idx++;
            }
            else {
                if(y1 > y2) {
                    int tmp = y1; y1 = y2; y2 = tmp;
                }
                Se[S_idx].x = x1; Se[S_idx].y1 = y1;
                Se[S_idx].y2 = y2; Se[S_idx].w = w; S_idx++;
            }
        }

        for(int i=0; i<G_idx; i++) {
            adj[S].push_back(1+i);
            adj[i+1].push_back(S);
            c[S][i+1] = 1;
            for(int j=0; j<S_idx; j++) {
                if(Ga[i].x1 <= Se[j].x && Se[j].x <= Ga[i].x2 && \
                    Se[j].y1 <= Ga[i].y && Ga[i].y <= Se[j].y2) {
                        adj[i+1].push_back(201+j);
                        adj[201+j].push_back(i+1);
                        c[i+1][201+j] = 1;
                        d[i+1][201+j] = -Ga[i].w * Se[j].w;
                        d[201+j][i+1] = Ga[i].w * Se[j].w;
                    }
            }
        }
        for(int i=0; i<S_idx; i++) {
            c[201+i][E] = 1;
            adj[201+i].push_back(E);
            adj[E].push_back(201+i);
        }

        pair<int, int> p = SPFA();
        printf("%d %d\n", p.first, -p.second);

    }
}
//# Author : nuclear852 ========================#
//# Solution : 24343755 ========================#
//# Time Stamp : 2020-12-13 00:55:58 ===========#
//# Problem Title : 거의 최단 경로 ===============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define MAX 999999999
using namespace std;

int N, M;
int S, D;

int adj[501][501];
vector<int> parent[501];
int dist[501];
bool visited[501];

void dijkstra(int start) {
    for(int i=0; i<=500; i++) visited[i] = 0;
    priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()) {
        pair<int, int> cur_info = pq.top(); pq.pop();
        int d = cur_info.first; int cur = cur_info.second;
        if(visited[cur]) continue;
        visited[cur] = true;

        for(int i=0; i<=N-1; i++) {
            if(adj[cur][i] == MAX) continue;
            if(d + adj[cur][i] < dist[i]) {
                parent[i].clear();
                dist[i] = d + adj[cur][i];
                pq.push({dist[i], i});
                parent[i].push_back(cur);
            }
            else if(d + adj[cur][i] == dist[i]) {
                parent[i].push_back(cur);
            }
        }
    }
}

void bfs(int start) {
    for(int i=0; i<=500; i++) visited[i] = 0;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto next: parent[cur]) {
            adj[next][cur] = MAX;
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    while(N!=0||M!=0) {
        for(int i=0; i<=500; i++) {
            for(int j=0; j<=500; j++) {
                adj[i][j] = MAX;
            }
            dist[i] = MAX;
            parent[i].clear();
        }
        scanf("%d%d", &S, &D);
        for(int i=1; i<=M; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            adj[a][b] = c;
        }

        dijkstra(S);
        bfs(D);
        for(int i=0; i<=500; i++) {
            dist[i] = MAX;
            parent[i].clear();
        }
        dijkstra(S);
        if(dist[D] == MAX) {
            printf("-1\n");
        }
        else {
            printf("%d\n", dist[D]);
        }


        scanf("%d%d", &N, &M);
    }
}
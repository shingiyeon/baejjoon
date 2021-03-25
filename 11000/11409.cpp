//# Author : nuclear852 ========================#
//# Solution : 22168871 ========================#
//# Time Stamp : 2020-08-30 22:29:04 ===========#
//# Problem Title : 열혈강호 6 =================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#define MAX 999999999
using namespace std;

int N, M;
vector<int> adj[805];

const int S = 0, E = 804;

int parent[805];
bool inQ[805];
int dist[805];

int c[805][805];
int f[805][805];
int d[805][805];

pair<int, int> MCMF() {
    int flow = 0, cost = 0;
    while(true) {
        for(int i=S; i<=E; i++) {
            parent[i] = -1;
            inQ[i] = 0;
            dist[i] = MAX;
        }

        queue<int> q;
        q.push(S); inQ[S] = 1; dist[S] = 0;
        while(!q.empty()) {
            int cur = q.front(); q.pop(); inQ[cur] = 0;
            for(auto next : adj[cur]) {
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

        if(parent[E] == -1) break;

        int cur_flow = MAX;
        for(int i=E; i!=S; i=parent[i]) cur_flow = min(cur_flow, c[parent[i]][i] - f[parent[i]][i]);
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
    scanf("%d%d", &N, &M);
    int num, a, b;
    for(int i=1; i<=N; i++) {
        adj[S].push_back(i);
        adj[i].push_back(S);
        c[S][i] = 1;
        scanf("%d", &num);
        for(int j=0; j<num; j++) {
            scanf("%d%d",&a,&b);
            adj[i].push_back(a+400);
            adj[a+400].push_back(i);
            c[i][a+400] = 1;
            d[i][a+400] = -b;
            d[a+400][i] = b;
        }
    }
    for(int i=1; i<=M; i++) {
        adj[400+i].push_back(E);
        c[400+i][E] = 1;
        adj[E].push_back(400+i);
    }
    pair<int, int> p = MCMF();
    printf("%d\n%d", p.first, -p.second);
}
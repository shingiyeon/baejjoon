//# Author : nuclear852 ========================#
//# Solution : 24984795 ========================#
//# Time Stamp : 2021-01-06 20:32:21 ===========#
//# Problem Title : 단방향 링크 네트워크 ============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
int T, N, M;
vector<int> adj[1001];
int lv[1001];
int checked[1001];
int A[1001], B[1001];

void bfs() {
    queue<int> q;
    for(int i=0; i<=1000; i++) {
        if(A[i] == -1) {
            lv[i] = 0;
            q.push(i);
        }
        else {
            lv[i] = -5;
        }
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto f: adj[cur]) {
            if(B[f] != -1 && lv[B[f]] == -5) {
                lv[B[f]] = lv[cur] + 1;
                q.push(B[f]);
            }
        }
    }
}

bool dfs(int cur) {
    for(int &i = checked[cur]; i < adj[cur].size(); i++) {
        int next = adj[cur][i];
        if(B[next] == -1) {
            A[cur] = next;
            B[next] = cur;
            return 1;
        }
        if(lv[B[next]] == lv[cur] + 1) {
            if(dfs(B[next])) {
                A[cur] = next;
                B[next] = cur;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        for(int i=0; i<1001; i++){
            A[i] = B[i] = -1;
            lv[i] = checked[i] = 0; adj[i].clear();
        }
        scanf("%d%d", &N, &M);

        for(int i=0; i<M; i++) {
            int a, b; scanf("%d%d", &a, &b);
            adj[a].push_back(b);
        }

        int max_flow = 0;

        while(true) {
            int flow = 0;
            bfs();
            for(int i=0; i<N; i++) checked[i] = 0;
            for(int i=0; i<N; i++) if(A[i]==-1 && dfs(i)) flow++;
            if(!flow) break;
            max_flow += flow;
        }
        printf("%d\n", max_flow);

    }
}
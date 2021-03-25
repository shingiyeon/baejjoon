//# Author : nuclear852 ========================#
//# Solution : 24039318 ========================#
//# Time Stamp : 2020-11-25 10:37:14 ===========#
//# Problem Title : 줄 세우기 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int indeg[32001];
vector<int> adj[32001];
bool visited[32001];
vector<int> ans;

int N, M;

int main() {
    int a, b;
    scanf("%d%d", &N, &M);
    queue<int> q;
    for(int i=1; i<=M; i++) {
        scanf("%d%d", &a, &b);
        indeg[b]++;
        adj[a].push_back(b);
    }
    for(int i=1; i<=N; i++) {
        if(indeg[i] == 0) {
            q.push(i);
            visited[i] = 1;
        }
    }

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for(auto next: adj[cur]) {
            indeg[next]--;
            if(indeg[next] == 0 && visited[next] == 0) {
                visited[next] = 1;
                q.push(next);
            }
        }
    }

    for(auto val: ans) {
        printf("%d ", val);
    }
}
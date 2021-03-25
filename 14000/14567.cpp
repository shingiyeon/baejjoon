//# Author : nuclear852 ========================#
//# Solution : 24385137 ========================#
//# Time Stamp : 2020-12-15 14:25:36 ===========#
//# Problem Title : 선수과목 (Prerequisite) ====#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[1001];
int N, M;
int indeg[1001];
int lv[1001];
int main() {
    scanf("%d%d", &N, &M);
    for(int i=1; i<=M; i++) {
        int a, b; scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        indeg[b]++;
    }
    queue<int> q;
    for(int i=1; i<=N; i++) {
        if(!indeg[i]) {
            q.push(i);
            lv[i] = 1;
        }
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto next: adj[cur]) {
            lv[next] = max(lv[next], lv[cur] + 1);
            indeg[next]--;
            if(!indeg[next]) {
                q.push(next);
            }
        }
    }
    for(int i=1; i<=N; i++) {
        printf("%d ", lv[i]);
    }
}
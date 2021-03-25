//# Author : nuclear852 ========================#
//# Solution : 24071474 ========================#
//# Time Stamp : 2020-11-26 23:29:55 ===========#
//# Problem Title : 문제집 ====================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> q;
int N, M;

int indeg[32001];
vector<short> adj[32001];
vector<int> ans;
int main() {
    scanf("%d%d", &N, &M);
    int a, b;
    for(int i=1; i<=M; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        indeg[b]++;
    }
    for(int i=1; i<=N; i++) {
        if(indeg[i] == 0) {
            q.push(-i);
        }
    }
    while(!q.empty()) {
        int cur = -q.top(); q.pop();
        ans.push_back(cur);

        for(auto next: adj[cur]) {
            indeg[next]--;
            if(indeg[next] == 0) {
                q.push(-next);
            }
        }
    }

    for(auto val: ans) {
        printf("%d ", val);
    }
}
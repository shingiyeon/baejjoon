//# Author : nuclear852 ========================#
//# Solution : 24375911 ========================#
//# Time Stamp : 2020-12-14 22:38:54 ===========#
//# Problem Title : 여행 계획 세우기 ==============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, S, T;

int indeg[10001];
bool inQ[10001];
int ans[10001];
int num[10001], gNum[10001], scc[10001], s_size[10001];
vector< vector<int> > adj;
vector< vector<int> > s_adj;

int cnt = 0, s_cnt = 0;
stack<int> s;
void dfs(int cur) {
    s.push(cur);
    inQ[cur] = true;
    num[cur] = ++cnt;
    gNum[cur] = cnt;

    for(auto next: adj[cur]) {
        if(!num[next]) {
            dfs(next);
            gNum[cur] = min(gNum[cur], gNum[next]);
        }
        else if(inQ[next]) {
            gNum[cur] = min(gNum[cur], num[next]);
        }
    }

    if(num[cur] == gNum[cur]) {
        s_cnt++;
        while(!s.empty()) {
            int s_cur = s.top(); s.pop();
            inQ[s_cur] = false;
            scc[s_cur] = s_cnt;
            s_size[s_cnt]++;
            if(s_cur == cur) break;
        }
    }
}

int main() {
    scanf("%d%d%d%d", &N, &M, &S, &T);
    adj.resize(N+1);
    s_adj.resize(N+1);

    for(int i=1; i<=M; i++) {
        int a, b; scanf("%d%d", &a, &b);
        adj[a].push_back(b);
    }
    // for(int i=1; i<=N; i++) {
    //     if(!num[i]) dfs(i);
    // }
    dfs(S);
    for(int cur=1; cur<=N; cur++) {
        for(auto next: adj[cur]) {
            if(scc[cur] != scc[next]) {
                s_adj[scc[cur]].push_back(scc[next]);
            }
        }
    }
    for(int i=1; i<=s_cnt; i++) {
        s_adj[i].erase(unique(s_adj[i].begin(), s_adj[i].end()), s_adj[i].end());
        for(auto next: s_adj[i]) {
            indeg[next]++;
        }
    }
    queue<int> q;
    for(int i=1; i<=s_cnt; i++) {
        if(!indeg[i]) {
            q.push(i);
            ans[i] = s_size[i];
        }
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto next: s_adj[cur]) {
            ans[next] = max(ans[next], s_size[next] + ans[cur]);
            indeg[next]--;
            if(!indeg[next]) {
                q.push(next);
            }
        }
    }
    printf("%d", ans[scc[T]]);
}
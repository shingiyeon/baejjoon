//# Author : nuclear852 ========================#
//# Solution : 25029480 ========================#
//# Time Stamp : 2021-01-07 22:51:32 ===========#
//# Problem Title : 범죄 파티 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int N, K;
int level[200002];
int aMatched[200002], bMatched[400002];
int checked[200002];
vector< pair<int, int> > adj[200002];

void bfs(int limit) {
    queue<int> q;
    for(int i=1; i<=N; i++) {
        if(aMatched[i] == -1) {
            level[i] = 0;
            q.push(i);
        }
        else {
            level[i] = -5;
        }
    }

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto info: adj[cur]) {
            if(info.first > limit) continue;
            int next = info.second;
            if(bMatched[next] != -1 && level[bMatched[next]] == -5) {
                level[bMatched[next]] = level[cur] + 1;
                q.push(bMatched[next]);
            }
        }
    }
}

bool dfs(int cur, int limit) {
    for(int i = checked[cur]; i < adj[cur].size(); i++) {
        auto info = adj[cur][i];
        int next = info.second;

        if(info.first > limit) continue;

        if(bMatched[next] == -1) {
            aMatched[cur] = next;
            bMatched[next]  = cur;
            return 1;
        }
        else if(level[bMatched[next]] == level[cur] + 1 && dfs(bMatched[next], limit)) {
            aMatched[cur] = next;
            bMatched[next] = cur;
            return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        for(int j=0; j<=1; j++) {
            int a, b; scanf("%d%d", &a, &b);
            adj[i].push_back({b,a});
        }
    }

    int start = 0, end = 1000000;

    while(start <= end) {
        int mid = (start + end) / 2;
        int tmp_ans = 0;

        for(int i=0; i<200002; i++) {
            aMatched[i] = -1;
        }
        for(int i=0; i<400002; i++) {
            bMatched[i] = -1;
        }

        while(true) {
            int flow = 0;
            for(int i=1; i<=N; i++) {
                checked[i] = 0;
            }
            bfs(mid);
            for(int i=1; i<=N; i++) {
                if(aMatched[i] == -1 && dfs(i, mid)) flow++;
            }
            if(!flow) break;
            tmp_ans += flow;
        }
        if(tmp_ans >= N) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    printf("%d", start > 1000000 ? -1 : start);
}
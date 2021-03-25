//# Author : nuclear852 ========================#
//# Solution : 25600284 ========================#
//# Time Stamp : 2021-01-23 23:29:07 ===========#
//# Problem Title : MT =====================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int dy[1001][1001];
int n, k;
int indeg_idx = 0;
vector<int> adj[1001];
vector<int> scc[1001];
int indeg[1001];
int iscc[1001];
int sz[1001];
int num[1001], gNum[1001];
int dmin[1001], dmax[1001];
bool inS[1001];
stack<int> S;
int cnt = 0, s_cnt = 0;

int d(int cur) {
    int tmp_max = sz[cur];
    for(auto next: scc[cur]) {
        auto next_d = d(next);
        tmp_max += next_d;
    }
    return tmp_max;
}

int ks(int num, int val) {
    if(num > indeg_idx) return 0;
    if(dy[num][val] != -1) return dy[num][val];
    dy[num][val] = ks(num + 1, val);
    for(int i=dmin[num]; i<=dmax[num]; i++) {
        if(i > val) break;
        dy[num][val] = max(dy[num][val], ks(num+1, val-i) + i);
    }
    return dy[num][val];
}

void dfs(int cur) {
    S.push(cur);
    num[cur] = ++cnt;
    gNum[cur] = num[cur];
    inS[cur] = true;

    for(auto next: adj[cur]) {
        if(!num[next]) {
            dfs(next);
            gNum[cur] = min(gNum[cur], gNum[next]);
        }
        else if(inS[next]) {
            gNum[cur] = min(gNum[cur], num[next]);
        }
    }

    if(num[cur] == gNum[cur]) {
        ++s_cnt;
        while(!S.empty()) {
            int s_cur = S.top(); S.pop();
            inS[s_cur] = false;
            iscc[s_cur] = s_cnt;
            sz[s_cnt]++;
            if(s_cur == cur) break;
        }
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=k; j++) {
            dy[i][j] = -1;
        }
    }
    for(int i=1; i<=n; i++) {
        int x; scanf("%d", &x);
        adj[x].push_back(i);
    }
    for(int i=1; i<=n; i++) {
        if(!num[i]) dfs(i);
    }

    for(int i=1; i<=n; i++) {
        for(auto next: adj[i]) {
            if(iscc[i] != iscc[next]) {
                scc[iscc[i]].push_back(iscc[next]);
                indeg[iscc[next]]++;
            }
        }
    }
    for(int i=1; i<=s_cnt; i++) {
        scc[i].erase(unique(scc[i].begin(), scc[i].end()), scc[i].end());
    }

    for(int i=1; i<=s_cnt; i++) {
        if(!indeg[i]) {
            indeg_idx++;
            auto p = d(i);
            dmin[indeg_idx] = sz[i]; dmax[indeg_idx] = p;
        }
    }
    printf("%d", ks(1, k));


}
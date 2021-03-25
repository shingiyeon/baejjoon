//# Author : nuclear852 ========================#
//# Solution : 24427584 ========================#
//# Time Stamp : 2020-12-17 17:11:09 ===========#
//# Problem Title : 자전거 경주 준비하기 ============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int N, M;

vector< vector<int> > adj;
vector< vector<int> > s_adj;
vector< vector<int> > SCC;
int scc[10001];
int s_size[10001];
long long lv[10001];
int indeg[10001];

bool flag[10001];
bool inQ[10001];
int num[10001];
int gNum[10001];

stack<int> S;
int cnt = 0, s_cnt = 0;
void dfs(int cur) {
    S.push(cur);
    inQ[cur] = true;
    num[cur] = ++cnt;
    gNum[cur] = num[cur];

    for(auto next: adj[cur]) {
        if(!num[next]) {
            dfs(next);
            gNum[cur] = min(gNum[cur], gNum[next]);
        }
        else if(inQ[next]) {
            gNum[cur] = min(gNum[cur], num[next]);
        }
    }

    if(gNum[cur] == num[cur]) {
        vector<int> t_scc;
        while(!S.empty()) {
            int s_cur = S.top(); S.pop();
            inQ[s_cur] = false;
            scc[s_cur] = s_cnt;
            t_scc.push_back(s_cur);
            if(s_cur == cur) break;
        }
        SCC.push_back(t_scc);
        s_cnt++;
    }
}

int main() {
    scanf("%d%d", &N, &M);
    adj.resize(N+1);
    s_adj.resize(N+1);
    for(int i=1; i<=M; i++) {
        int a, b; scanf("%d%d", &a, &b);
        adj[a].push_back(b);
    }
    
    dfs(1);

    for(int i=SCC.size()-1; i>=0; i--) {
        for(auto cur: SCC[i]) {
            for(auto next: adj[cur]) {
                if(scc[cur] != scc[next]) {
                    s_adj[scc[cur]].push_back(scc[next]);
                    indeg[scc[next]]++;
                }
            }
        }
    }

    queue<int> q;
    for(int i=0; i<s_cnt; i++) {
        if(!indeg[i]) {
            if(SCC[i].size() > 1) {
                q.push(i);
                lv[i] = -1;
            }
            else {
                q.push(i);
                lv[i] = 1;
            }
        }
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto next: s_adj[cur]) {
            if(lv[cur] == -1 || lv[next] == -1 || SCC[next].size() > 1) {
                lv[next] = -1;
            } 
            else {
                lv[next] += lv[cur];
                if (lv[next] >= 1000000000 || flag[cur] == true) {
                    flag[next] = true;
                }
                lv[next] %= 1000000000;
            }
            indeg[next]--;
            if(!indeg[next]) {
                q.push(next);    
            }
        }
    }

    if(lv[scc[2]] == -1) {
        printf("inf");
    }
    else {
        if (flag[scc[2]]) {
            printf("%09lld", lv[scc[2]]);
        }
        else {
            printf("%lld", lv[scc[2]]);
        }
    }
}
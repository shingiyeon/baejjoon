//# Author : nuclear852 ========================#
//# Solution : 24364440 ========================#
//# Time Stamp : 2020-12-14 13:48:43 ===========#
//# Problem Title : ATM ====================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int num[500001], gNum[500001];
bool inS[500001];
int scc[500001];
stack<int> S;
int cnt = 0, s_cnt = 0;
int arr[500001];
int sarr[500001];
int hap[500001];
bool isRest[500001];
bool hasRest[500001];
int indeg[500001];
vector< vector<int> > adj;
vector< vector<int> > s_adj;
int N, M;
int s, p;
void dfs(int cur) {
    S.push(cur);
    inS[cur] = true;
    num[cur] = ++cnt;
    gNum[cur] = num[cur];

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
        int sum = 0;
        bool rest = false;
        while(!S.empty()) {
            int s_cur = S.top(); S.pop();
            inS[s_cur] = false;
            scc[s_cur] = s_cnt;
            rest |= isRest[s_cur];
            sum += arr[s_cur];
            if(s_cur == cur) break;
        }
        hasRest[s_cnt] = rest;
        sarr[s_cnt] = sum;
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
    for(int i=1; i<=N; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d%d", &s, &p);
    for(int i=1; i<=p; i++) {
        int tmp; scanf("%d", &tmp);
        isRest[tmp] = true;
    }
    dfs(s);
    for(int cur=1; cur<=N; cur++) {
        for(auto next: adj[cur]) {
            if(scc[cur] != scc[next]) {
                s_adj[scc[cur]].push_back(scc[next]);
            }
        }
    }
    for(int cur=1; cur<=s_cnt; cur++) {
        s_adj[cur].erase(unique(s_adj[cur].begin(), s_adj[cur].end()), s_adj[cur].end());
        for(auto next: s_adj[cur]) {
            indeg[next]++;
        }
    }

    int answer = 0;
    queue<int> q;
    for(int i=1; i<=s_cnt; i++) {
        if(indeg[i] == 0) {
            hap[i] = sarr[i];
            q.push(i);
        }
    }

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(hasRest[cur]) {
            answer = max(answer, hap[cur]);
        }
        for(auto next: s_adj[cur]) {
            hap[next] = max(hap[next], sarr[next] + hap[cur]);
            indeg[next]--;
            if(indeg[next] == 0) {
                q.push(next);
            }
        }
    }
    printf("%d", answer);
}
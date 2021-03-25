//# Author : nuclear852 ========================#
//# Solution : 24396936 ========================#
//# Time Stamp : 2020-12-15 23:34:07 ===========#
//# Problem Title : 검색 엔진 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;
using std::string;

int N;
map<string, int> m;
map<string, int>::iterator it;
vector< vector<int> > adj;
vector< vector<int> > s_adj;
vector<int> SCC[5001];
int indeg[5001];
long long lv[5001];
int scc[5001], num[5001], gNum[5001];
bool inQ[5001];
stack<int> S;
int cnt = 0, s_cnt = 0;
int stringN = 0;

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
        if(inQ[next]) {
            gNum[cur] = min(gNum[cur], num[next]);
        }
    }

    if(gNum[cur] == num[cur]) {
        s_cnt++;
        while(!S.empty()) {
            int s_cur = S.top(); S.pop();
            inQ[s_cur] = false;
            scc[s_cur] = s_cnt;
            SCC[s_cnt].push_back(s_cur);
            if(s_cur == cur) break; 
        }
    }
}

vector<int> topological() {
    vector<int> v;
    for(int i=1; i<=stringN; i++) {
        for(auto next: adj[i]) {
            if(scc[i] != scc[next]) {
                s_adj[scc[i]].push_back(scc[next]);
            }
        }
    }
    queue<int> q;
    for(int i=1; i<=s_cnt; i++) {
        s_adj[i].erase(unique(s_adj[i].begin(), s_adj[i].end()), s_adj[i].end());
        for(auto next: s_adj[i]) {
            indeg[next]++;
        }
    }
    for(int i=1; i<=s_cnt; i++) {
        if(!indeg[i]) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        v.push_back(cur);
        for(auto next: s_adj[cur]) {
            indeg[next]--;
            if(!indeg[next]) {
                q.push(next);
            }
        }
    }
    return v;
}

int main() {
    char temp[101];
    scanf("%d", &N);
    adj.resize( N*50 + 51);
    s_adj.resize( N*50 + 51);
    for(int i=1; i<=N; i++) {
        string A, B; int n;
        scanf("%s%d", temp, &n);
        A = temp;
        it = m.find(A);
        if(it == m.end()) {
            m[A] = ++stringN;
        }
        for(int j=1; j<=n; j++) {
            scanf("%s", temp);
            B = temp;
            it = m.find(B);
            if(it == m.end()) {
                m[B] = ++stringN;
            }
            adj[m[B]].push_back(m[A]);
        }
    }

    for(int i=1; i<=stringN; i++) {
        if(!num[i]) dfs(i);
    }
    vector<int> v = topological();
    
    scanf("%s", temp);
    string s = temp;
    for(int i=1; i<=stringN; i++) {
        lv[i] = 1;
        //printf("%d %d\n", i, scc[i]);
    }
    for(int order: v) {
        //printf("%d ", order);
        for(auto cur: SCC[order]) {
            for(auto next: adj[cur]) {
                if(scc[cur] != scc[next]) {
                    lv[next] += lv[cur];
                }
            }
        }
    }
    printf("%lld", lv[m[s]]);

    
}
//# Author : nuclear852 ========================#
//# Solution : 24362213 ========================#
//# Time Stamp : 2020-12-14 10:57:55 ===========#
//# Problem Title : 2-SAT - 4 ==============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int num[20002], gNum[20002];
bool inS[20002];
int scc[20002];
stack<int> S;
int cnt = 0, s_cnt = 0;
vector<int> adj[20002];
int N, M;

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
        while(!S.empty()) {
            int s_cur = S.top(); S.pop();
            inS[s_cur] = false;
            scc[s_cur] = s_cnt;
            if(s_cur == cur) break;
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=1; i<=M; i++) {
        int a, b; scanf("%d%d", &a, &b);
        if(a<0) a = -a + 10000;
        if(b<0) b = -b + 10000;

        if(a > 10000) {
            adj[a-10000].push_back(b);
        }
        else {
            adj[a+10000].push_back(b);
        }
        if(b > 10000) {
            adj[b-10000].push_back(a);
        }
        else {
            adj[b+10000].push_back(a);
        }
    }

    for(int i=1; i<=N; i++) {
        if(!num[i]) dfs(i);
        if(!num[i+10000]) dfs(i+10000);
    }

    bool pos = 1;
    for(int i=1; i<=N; i++) {
        if(scc[i] == scc[i+10000]) pos = 0;
    }
    if(!pos) printf("0");
    else {
        printf("1\n");
        for(int i=1; i<=N; i++) {
           printf("%d ", scc[i] < scc[i+10000]);
        }
    }
    

}
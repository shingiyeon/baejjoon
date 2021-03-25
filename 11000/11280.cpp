//# Author : nuclear852 ========================#
//# Solution : 24328510 ========================#
//# Time Stamp : 2020-12-11 23:40:37 ===========#
//# Problem Title : 2-SAT - 3 ==============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <cassert>
using namespace std;
int N, M;

vector< int > adj[20001];

int num[20001];
int gNum[20001];
int indeg[20001];
int scc[20001];
bool inQ[20001];

stack<int> s;

int cnt = 0;
int s_cnt = 0;
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

    if(gNum[cur] == num[cur]) {
        ++s_cnt;
        while(!s.empty()) {
            int s_cur = s.top(); s.pop();
            inQ[s_cur] = false;
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
        } else {
            adj[a+10000].push_back(b);
        }

        if(b > 10000) {
            adj[b-10000].push_back(a);
        } else{
            adj[b+10000].push_back(a);
        }

        assert(a > 0 && a <= 20000);
        assert(b > 0 && b <= 20000);
    }

    for(int i=1; i<=N; i++) {
        if(!num[i]) dfs(i);
        if(!num[i+10000]) dfs(i+10000);
    }

    int pos = 1;
    for(int i=1; i<=N; i++) {
        if(scc[i] == scc[i+10000]) pos = 0;
    }


    printf("%d", pos);
}
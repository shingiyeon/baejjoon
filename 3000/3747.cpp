//# Author : nuclear852 ========================#
//# Solution : 24638155 ========================#
//# Time Stamp : 2020-12-26 22:30:11 ===========#
//# Problem Title : 완벽한 선거! ================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int N, M;
vector<int> adj[2020];
int num[2020], gNum[2020], scc[2020];
bool inS[2020];
stack<int> S;
int cnt = 0, s_cnt = 0;

int org(int a) {
    if(a<0) return -a + 1000;
    return a;
}
int rev(int a) {
    if(a>1000) return a - 1000;
    return a + 1000;
}

void make_scc(int cur) {
    S.push(cur);
    num[cur] = ++cnt;
    gNum[cur] = num[cur];
    inS[cur] = true;

    for(auto next: adj[cur]) {
        if(!num[next]) {
            make_scc(next);
            gNum[cur] = min(gNum[cur], gNum[next]);
        }
        else if(inS[next]) {
            gNum[cur] = min(gNum[cur], num[next]);
        }
    }

    if(num[cur] == gNum[cur]) {
        s_cnt++;
        while(!S.empty()) {
            int s_cur = S.top(); S.pop();
            scc[s_cur] = s_cnt;
            inS[s_cur] = false;
            if(cur == s_cur) break;
        }
    }
}

int main() {
    while(scanf("%d%d", &N, &M) != EOF) {
        cnt = s_cnt = 0;
        for(int i=0; i<2020; i++) {
            adj[i].clear();
            num[i] = gNum[i] = scc[i] = inS[i] = 0;
        }
        while(!S.empty()) S.pop();
        for(int i=0; i<M; i++) {
            int a, b; scanf("%d%d", &a, &b); a = org(a); b = org(b);
            adj[rev(b)].push_back(a);
            adj[rev(a)].push_back(b);
        }
        for(int i=1; i<=N; i++) {
            if(!num[i]) make_scc(i);
            if(!num[i+1000]) make_scc(i);
        }
        bool pos = true;
        for(int i=1; i<=N; i++) {
            if(scc[i] == scc[i+1000]) pos = false;
        }
        printf("%d\n", pos);
    }
}
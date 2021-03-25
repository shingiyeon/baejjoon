//# Author : nuclear852 ========================#
//# Solution : 24637882 ========================#
//# Time Stamp : 2020-12-26 22:21:28 ===========#
//# Problem Title : 가위바위보 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int N, M;
int num[20200], gNum[20200];
int scc[20200];
bool inS[20200];
stack<int> S;
vector<int> adj[20200];
int cnt = 0, s_cnt = 0;

int inv(int n) {
    if(n > 10000) {
        return n - 10000;
    }
    return n + 10000;
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
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++) {
        int a, b; scanf("%d%d", &a, &b);
        a = a < 0 ? -a + 10000 : a;
        b = b < 0 ? -b + 10000 : b;
        adj[inv(b)].push_back(a);
        adj[inv(a)].push_back(b);
    }

    for(int i=1; i<=M; i++) {
        if(!num[i]) make_scc(i);
        if(!num[i+10000]) make_scc(i);
    }
    bool pos = true;
    for(int i=1; i<=M; i++) {
        if(scc[i] == scc[i+10000]) pos = false;
    }
    if(pos) printf("^_^");
    else printf("OTL");
}
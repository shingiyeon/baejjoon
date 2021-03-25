//# Author : nuclear852 ========================#
//# Solution : 24580132 ========================#
//# Time Stamp : 2020-12-24 14:51:53 ===========#
//# Problem Title : 아이돌 ====================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

stack<int> S;
vector<int> adj[2020];
int num[2020], gNum[2020];
bool inS[2020];
int scc[2020];
int cnt = 0, s_cnt = 0;
int n, m;

int inv(int k) {
    if(k<0) return -k;
    else return k + 1000;
}

int org(int k) {
    if(k<0) return -k + 1000;
    else return k;
}

void dfs(int cur) {
    S.push(cur);
    num[cur] = ++cnt;
    gNum[cur] = cnt;
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
        s_cnt++;
        while(!S.empty()) {
            int s_cur = S.top(); S.pop();
            scc[s_cur] = s_cnt;
            inS[s_cur] = false;
            if(cur == s_cur) break;
        }
    }
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF) {
        for(int i=0; i<2020; i++) {
            adj[i].clear(); num[i] = gNum[i] = inS[i] = scc[i] = 0;
            while(!S.empty()) S.pop();
        }
        cnt = s_cnt = 0;
        adj[1001].push_back(1);
        for(int i=1; i<=m; i++) {
            int a, b; scanf("%d%d",&a,&b);
            adj[inv(a)].push_back(org(b));
            adj[inv(b)].push_back(org(a));
        }
        for(int i=1; i<=n; i++) {
            if(!num[i]) dfs(i);
            if(!num[i+1000]) dfs(i+1000);
        }
        bool pos = true;
        for(int i=1; i<=n; i++) {
            if(scc[i] == scc[i+1000]) {
                pos = false;
            }
        }
        if(pos) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }
}
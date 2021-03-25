//# Author : nuclear852 ========================#
//# Solution : 24674701 ========================#
//# Time Stamp : 2020-12-28 10:47:36 ===========#
//# Problem Title : 괴도 강산 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int N, M;
int cnt = 0, s_cnt = 0;
vector<int> adj[4040];
stack<int> S;
int scc[4040], num[4040], gNum[4040];
bool inS[4040];
char map[1005][1005];

int inv(int n) {
    if(n > 2000) return n - 2000;
    else return n + 2000;
}

void make_scc(int cur) {
    S.push(cur);
    num[cur] = ++cnt;
    gNum[cur] = cnt;
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
            inS[s_cur] = false;
            scc[s_cur] = s_cnt;
            if(cur == s_cur) break;
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++) scanf("%s", map[i]);

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(map[i][j] == '#') {
                int garo = i + 1, sero = j + 1 + 1000;
                adj[garo].push_back(sero);
                adj[sero].push_back(garo);
                adj[inv(garo)].push_back(inv(sero));
                adj[inv(sero)].push_back(inv(garo));
            }
            else if(map[i][j] == '*') {
                int garo = i + 1, sero = j + 1 + 1000;
                adj[garo].push_back(inv(sero));
                adj[sero].push_back(inv(garo));
                adj[inv(sero)].push_back(garo);
                adj[inv(garo)].push_back(sero);
            }
        }
    }
    for(int i=1; i<=N; i++) {
        if(!num[i]) make_scc(i);
        if(!num[inv(i)]) make_scc(inv(i));
    }
    for(int i=1; i<=M; i++) {
        if(!num[i+1000]) make_scc(i+1000);
        if(!num[inv(i+1000)]) make_scc(inv(i+1000));
    }
    bool pos = true;

    for(int i=1; i<=N; i++) {
        if(scc[i] == scc[inv(i)]) pos = false;
    }
    for(int i=1; i<=M; i++) {
        if(scc[i+1000] == scc[inv(i+1000)]) pos = false;
    }
    printf("%d", pos);
}
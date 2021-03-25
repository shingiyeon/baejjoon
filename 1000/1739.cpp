//# Author : nuclear852 ========================#
//# Solution : 24673573 ========================#
//# Time Stamp : 2020-12-28 09:32:03 ===========#
//# Problem Title : 도로 정비하기 ================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int T, N, M, K;
int cnt = 0, s_cnt = 0;
vector<int> adj[4040];
stack<int> S;
int scc[4040], num[4040], gNum[4040];
bool inS[4040];

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
    scanf("%d", &T);
    while(T--) {
        for(int i=0; i<4040; i++) {
            adj[i].clear(); scc[i] = num[i] = gNum[i] = inS[i] = 0;
        }
        cnt = s_cnt = 0;
        while(!S.empty()) S.pop();

        scanf("%d%d%d", &N, &M, &K);

        for(int i=0; i<K; i++) {
            int a,b,x,y,a2,b2,x2,y2;
            scanf("%d%d%d%d", &a, &b, &x, &y);
            b += 1000; y += 1000;
            a2=a; b2=b; x2=x; y2=y;

            if(b>y) {
                a2 = inv(a2); x2 = inv(x2);
            }
            if(a>x) {
                b2 = inv(b2); y2 = inv(y2);
            }
            if(a2!=x2 && b2!=y2) {
                adj[inv(b2)].push_back(a2);
                adj[inv(a2)].push_back(b2);
                adj[inv(a2)].push_back(x2);
                adj[inv(x2)].push_back(a2);
                adj[inv(b2)].push_back(y2);
                adj[inv(y2)].push_back(b2);
                adj[inv(y2)].push_back(x2);
                adj[inv(x2)].push_back(y2);
            }
            else if(a2 == x2 && b2 != y2) {
                adj[inv(a2)].push_back(a2);
            }
            else if(a2 != x2 && b2 == y2) {
                adj[inv(b2)].push_back(b2);
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
        if(pos) printf("Yes\n");
        else printf("No\n");
    }
}
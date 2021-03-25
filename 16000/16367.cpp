//# Author : nuclear852 ========================#
//# Solution : 24640427 ========================#
//# Time Stamp : 2020-12-26 23:42:18 ===========#
//# Problem Title : TV Show Game ===========#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int K, N; 
int num[20202], gNum[20202];
vector<int> adj[20202];
bool inS[20202];
int scc[20202];
stack<int> S;
int cnt = 0 , s_cnt = 0;

int ori(int n, char c) {
    if(c == 'B') {
        return 10000+n;
    }
    return n;
}

int rev(int n) {
    if(n > 10000) return n - 10000;
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
    scanf("%d%d", &K, &N);
    for(int i=1; i<=N; i++) {
        int a,b,c; char x,y,z; scanf("%d %c %d %c %d %c", &a,&x,&b,&y,&c,&z);
        a = ori(a, x); b = ori(b, y); c = ori(c, z);
        adj[rev(a)].push_back(b);
        adj[rev(a)].push_back(c);
        adj[rev(b)].push_back(a);
        adj[rev(b)].push_back(c);
        adj[rev(c)].push_back(a);
        adj[rev(c)].push_back(b);
    }  

    for(int i=1; i<=K; i++) {
        if(!num[i]) make_scc(i);
        if(!num[i+10000]) make_scc(i+10000);
    }
    bool pos = true;
    for(int i=1; i<=K; i++) {
        if(scc[i] == scc[i+10000]) pos = false;
    }
    if(pos) {
        for(int i=1; i<=K; i++) {
            printf("%c", scc[i] < scc[i+10000] ? 'R' : 'B');
        }
    }
    else {
        printf("-1");
    }
}
//# Author : nuclear852 ========================#
//# Solution : 24385529 ========================#
//# Time Stamp : 2020-12-15 14:43:10 ===========#
//# Problem Title : Chess Tournament =======#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
int N, M;
vector< vector<int> > adj;
int indeg[50001];
int p[50001];


struct Query{
    int a, b;
    bool sym;
}Q[250001];

int parent(int cur) {
    if(p[cur] == cur) {
        return p[cur];
    }
    return p[cur] = parent(p[cur]);
}

void connect(int x, int y) {
    int pX = parent(x);
    int pY = parent(y);
    if(pX == pY) return;
    else {
        if(pX < pY) {
            p[pY] = pX;
        }
        else {
            p[pX] = pY;
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    adj.resize(N+1);
    for(int i=0; i<N; i++) {
        p[i] = i;
    }
    for(int i=0; i<M; i++) {
        int a, b; char c;
        scanf("\n%d %c %d", &a, &c, &b);
        if(c == '=') {
            Q[i].a = a; Q[i].b=b; Q[i].sym=0;
        }
        else {
            Q[i].a = a; Q[i].b=b; Q[i].sym=1;
        }
    }
    for(int i=0; i<M; i++) {
        if(!Q[i].sym) {
            connect(Q[i].a, Q[i].b);
        }
    }
    for(int i=0; i<M; i++) {
        if(Q[i].sym) {
            adj[parent(Q[i].a)].push_back(parent(Q[i].b));
            indeg[parent(Q[i].b)]++;
        }
    }
    queue<int> q;
    for(int i=0; i<N; i++) {
        if(!indeg[i]) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto next: adj[cur]) {
            indeg[next]--;
            if(!indeg[next]) {
                q.push(next);
            }
        }
    }
    bool pos = 1;
    for(int i=0; i<N; i++) {
        if(indeg[i]) pos = 0;
    }
    if(pos) {
        printf("consistent");
    }
    else {
        printf("inconsistent");
    }
}
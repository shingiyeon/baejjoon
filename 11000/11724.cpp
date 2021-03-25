//# Author : nuclear852 ========================#
//# Solution : 22748605 ========================#
//# Time Stamp : 2020-09-22 22:26:29 ===========#
//# Problem Title : 연결 요소의 개수 ==============#
//# Language : C++14 ===========================#

#include <stdio.h>

using namespace std;

int N, M;
int p[1001];
int rank[1001];
bool checked[1001];

int parent(int x) {
    if(p[x] == x) {
        return p[x];
    }
    return p[x] = parent(p[x]);
}

void sum(int x, int y) {
    if(parent(x) == parent(y)) return;

    if(rank[x] > rank[y]) {
        p[parent(y)] = parent(x);
        rank[x] += rank[y];
    }
    else {
        p[parent(x)] = parent(y);
        rank[y] += rank[x];
    }
}

int main(){
    for(int i=1; i<=1000; i++) {
        p[i] = i;
        rank[i] = 1;
    }

    scanf("%d%d", &N, &M);
    int u, v;
    for(int i=1; i<=M; i++) {
        scanf("%d%d", &u, &v);
        sum(u, v);
    }
    for(int i=1; i<=N; i++) {
        checked[parent(i)] = 1;
    }
    int ans = 0;
    for(int i=1; i<=N; i++) ans += checked[i];
    printf("%d", ans);
}
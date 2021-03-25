//# Author : nuclear852 ========================#
//# Solution : 22750372 ========================#
//# Time Stamp : 2020-09-22 23:22:18 ===========#
//# Problem Title : 난개발 ====================#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <algorithm>
using namespace std;

int N, M;
long long tree[800010];
long long lazy[800010];
struct Point{
    int x, y;
    int rnk;
    int index;
}P[200001], Q[200001];

bool cmp(struct Point a, struct Point b) {
    return a.y < b.y;
}

long long MAX(int index, int start, int end) {
    if(lazy[index] != 0) {
        tree[index] += lazy[index];
        if(start != end) {
            lazy[index * 2] += lazy[index];
            lazy[index * 2 + 1] += lazy[index];
        } 
        lazy[index] = 0;
    }

    if(start == end) {
        return tree[index];
    }
    int mid = (start + end) / 2;
    return max(MAX(index * 2, start , mid), MAX(index *2 + 1, mid + 1, end));
}

void update(int index, int start, int end, int left, int right, long long value) {
    if(lazy[index] != 0) {
        tree[index] += lazy[index];
        if(start != end) {
            lazy[index * 2] += lazy[index];
            lazy[index * 2 + 1] += lazy[index];
        } 
        lazy[index] = 0;
    }

    if(end < left || right < start) return;
    if(left <= start && end <= right) {
        tree[index] += value;
        if(start != end) {
            lazy[index * 2] += value;
            lazy[index * 2 + 1] += value;
        }
        return;
    }
    if(start == end) return;
    int mid = (start + end) / 2;
    update(index * 2, start, mid, left, right, value);
    update(index * 2 + 1, mid + 1, end, left, right, value);
}


int main() {
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++) {
        scanf("%d%d", &P[i].x, &P[i].y);
        P[i].index = i;
    }
    sort(P+1, P+N+1, cmp);
    int index = 1;
    P[1].rnk = 1;
    for(int i=2; i<=N; i++) {
        if(P[i].y == P[i-1].y) {
            P[i].rnk = index;
        }
        else {
            P[i].rnk = ++index;
        }
    }
    for(int i=1; i<=N; i++) {
        Q[P[i].index].x = P[i].x;
        Q[P[i].index].y = P[i].y;
        Q[P[i].index].rnk = P[i].rnk;
    }
    int u, v;
    long long value;
    for(int i=1; i<=M; i++) {
        scanf("%d%d%lld", &u, &v, &value);
        int left = Q[u].rnk;
        int right = Q[v].rnk;
        if (left > right) swap(left, right);
        update(1, 1, N, left, right, value);
    }

    printf("%lld", MAX(1, 1, N));

}
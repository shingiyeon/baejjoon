//# Author : nuclear852 ========================#
//# Solution : 24147532 ========================#
//# Time Stamp : 2020-12-01 15:36:22 ===========#
//# Problem Title : 수열과 쿼리 16 ==============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <utility>
#define INF 1000000000000LL
typedef long long ll;
using namespace std;

int N, M;

pair<ll, ll> tree[400020];
ll arr[100001];

void init(int index, int start, int end) {
    if(start == end) {
        tree[index] = {start, arr[start]};
        return;
    }
    int mid = (start + end) / 2;
    init(index * 2, start, mid);
    init(index * 2 + 1, mid + 1, end);

    if(tree[index*2].second <= tree[index*2+1].second) {
        tree[index] = tree[index*2];
    }
    else {
        tree[index] = tree[index*2+1];
    }
}

void update(int index, int start, int end, int cur, int val) {
    if(cur < start || end < cur) return;
    if(start == end) {
        tree[index] = {cur, val};
        return;
    }
    int mid = (start + end) / 2;
    update(index * 2, start, mid, cur, val);
    update(index * 2 + 1, mid + 1, end, cur, val);
    if(tree[index*2].second <= tree[index*2+1].second) {
        tree[index] = tree[index*2];
    }
    else {
        tree[index] = tree[index*2+1];
    }
} 

pair<ll, ll> find(int index, int start, int end, int left, int right) {
    if(start > right || end < left) return {0, INF};
    if(left <= start && end <= right) {
        return tree[index];
    }
    if(start == end) return {0, INF};
    int mid = (start + end) / 2;
    pair<ll, ll> lT = find(index * 2, start, mid, left, right);
    pair<ll, ll> rT = find(index * 2 + 1, mid + 1, end, left, right);
    if(lT.second <= rT.second) {
        return lT;
    }
    else {
        return rT;
    }
} 

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%lld", &arr[i]);
    init(1, 1, N);
    scanf("%d", &M);
    int Q, i, v;
    while(M--) {
        scanf("%d", &Q);
        if(Q == 1) {
            scanf("%d%d", &i, &v);
            update(1, 1, N, i, v);
            arr[i] = v;
        }
        else {
            scanf("%d%d", &i, &v);
            pair<int, int> T = find(1, 1, N, i, v);
            printf("%lld\n", T.first);
        }
    }
}
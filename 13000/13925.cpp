//# Author : nuclear852 ========================#
//# Solution : 23757414 ========================#
//# Time Stamp : 2020-11-09 23:57:09 ===========#
//# Problem Title : 수열과 쿼리 13 ==============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#define Mo 1000000007
typedef long long ll;

using namespace std;

int N, M;
ll tree[404040];
pair<ll, ll> lazy[404040];
ll arr[101010];
void init(int index, int start, int end) {
    if(start == end) {
        tree[index] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    init(index * 2, start, mid);
    init(index * 2 + 1, mid + 1, end);
    tree[index] = (tree[index*2]+ tree[index*2+1]) % Mo;
}

void updateLazy(int index, int start, int end, int left, int right) {
    pair<ll, ll> &c = lazy[index];
    if(c.first != 1 || c.second != 0) {
        tree[index] = (tree[index] * c.first + c.second * (end - start + 1)) % Mo;
        if(start != end) {
            pair<ll, ll> &l = lazy[index * 2];
            pair<ll, ll> &r = lazy[index * 2 + 1];
            l.first *= c.first;
            l.second = c.first * l.second + c.second;
            l.first %= Mo; l.second %= Mo;
            r.first *= c.first;
            r.second = c.first * r.second + c.second;
            r.first %= Mo; r.second %= Mo;
        }
        c.first = 1;
        c.second = 0;
    }
}

void update(int index, int start, int end, int left, int right, ll a, ll b) {
    updateLazy(index, start, end, left, right);
    if(right < start || left > end) return;
    if(left <= start && end <= right) {
        pair<ll, ll> &c = lazy[index];
        c.first = c.first * a;
        c.second = (c.second * a) + b;
        c.first %= Mo; c.second %= Mo;
        updateLazy(index, start, end, left, right);
        return;
    }
    int mid = (start + end) / 2;
    update(index * 2, start, mid, left, right, a, b);
    update(index * 2 + 1, mid + 1, end, left, right, a, b);
    tree[index] = (tree[index*2] + tree[index*2+1]) % Mo;
    return;
}

ll find(int index, int start, int end, int left, int right) {
    updateLazy(index, start, end, left, right);
    if(right < start || left > end) return 0;
    if(left <= start && end <= right) {
        return tree[index];
    }
    if(start == end) return 0;
    int mid = (start + end) / 2;
    return (find(index * 2, start, mid, left, right) + find(index *2 + 1, mid + 1, end, left, right)) % Mo;
}


int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%lld", &arr[i]);
    init(1, 1, N);
    scanf("%d", &M);
    for(int i=0; i<404040; i++) {
        lazy[i].first = 1;
        lazy[i].second = 0;
    }
    for(int i=1; i<=M; i++) {
        int ch; int x, y; ll v;
        scanf("%d", &ch);
        if(ch == 1) {
            scanf("%d%d%lld", &x, &y, &v);
            update(1, 1, N, x, y, 1, v);
        }
        else if(ch == 2) {
            scanf("%d%d%lld", &x, &y, &v);
            update(1, 1, N, x, y, v, 0);
        }
        else if(ch == 3) {
            scanf("%d%d%lld", &x, &y, &v);
            update(1, 1, N, x, y, 0, v);
        }
        else {
            scanf("%d%d", &x, &y);
            printf("%lld\n", find(1, 1, N, x, y));
        }

    }
}
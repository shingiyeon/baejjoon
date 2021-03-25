//# Author : nuclear852 ========================#
//# Solution : 24501543 ========================#
//# Time Stamp : 2020-12-21 13:56:33 ===========#
//# Problem Title : 수열과 쿼리 9 ===============#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
int sq;
int treeA[101010], treeB[101010];
int arrA[101010], arrB[101010];
long long ans[101010];
struct Query{
    int left, right, index, k;
}Q[100001];

bool cmp(const struct Query& l, const struct Query& r) {
    int lR = l.right / sq;
    int rR = r.right / sq;
    return lR == rR ? l.left < r.left : lR < rR;
}

void update(int (&tree)[101010], int cur, int diff) {
    while(cur <= 100000) {
        tree[cur] += (long long)diff;
        cur += (cur & -cur);
    }
}

long long sum(int tree[101010], int cur) {
    long long ans = 0;
    while(cur > 0) {
        ans += (long long)tree[cur];
        cur -= (cur & -cur);
    }
    return ans;
}

void f(int cur, bool add) {
    if(add) {
        update(treeA, arrA[cur], 1);
        update(treeB, arrB[cur], 1);
    }
    else {
        update(treeA, arrA[cur], -1);
        update(treeB, arrB[cur], -1);
    }
}

long long find(int k) {
    int sqk = (int)sqrt(k);
    long long ret = 0;
    for(int i=1; i<=sqk; i++) {
        ret += (sum(treeA, i) - sum(treeA, i-1)) * (sum(treeB, (int)k/i) - sum(treeB, sqk));
    }
    for(int i=1; i<=sqk; i++) {
        ret += (sum(treeB, i) - sum(treeB, i-1)) * (sum(treeA, (int)k/i) - sum(treeA, 0));
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    sq = (int)sqrt(N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &arrA[i]);
    }
    for(int i=1; i<=N; i++) {
        scanf("%d", &arrB[i]);
    }
    scanf("%d", &M);
    for(int i=1; i<=M; i++) {
        scanf("%d%d%d", &Q[i].left, &Q[i].right, &Q[i].k);
        Q[i].index = i;
    }
    sort(Q+1, Q+M+1, cmp);

    int low = Q[1].left;
    int high = Q[1].right;
    for(int i=low; i<=high; i++) {
        f(i, true);
    }
    ans[Q[1].index] = find(Q[1].k);
    for(int i=2; i<=M; i++) {
        while(low > Q[i].left) {
            f(--low, true);
        }
        while(high < Q[i].right) {
            f(++high, true);
        }
        while(low < Q[i].left) {
            f(low++, false);
        }
        while(high > Q[i].right) {
            f(high--, false);
        }
        ans[Q[i].index] = find(Q[i].k);
    }
    for(int i=1; i<=M; i++) {
        printf("%lld\n", ans[i]);
    }
}
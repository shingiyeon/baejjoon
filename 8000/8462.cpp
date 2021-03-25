//# Author : nuclear852 ========================#
//# Solution : 23871914 ========================#
//# Time Stamp : 2020-11-15 22:26:22 ===========#
//# Problem Title : 배열의 힘 ==================#
//# Language : C++17 ===========================#

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
typedef long long ll;
using namespace std;

int arr[100001];
ll ans[100001];
int cnt[1000001];
ll sum = 0;
int n, t;
int sq;

struct Query{
    int left, right, index;
}Q[100001];

bool cmp(const struct Query &a, const struct Query &b) {
    int aR = a.right / sq;
    int bR = b.right / sq;

    return aR == bR ? a.left < b.left : aR < bR;
}

void f(int index, bool add) {
    if(add) {
        sum += (ll) ( cnt[arr[index]] * 2 + 1 ) * arr[index];
        cnt[arr[index]]++;
    }
    else {
        sum -= (ll) ( cnt[arr[index]] * 2 - 1) * arr[index];
        cnt[arr[index]]--;
    }
}

int main() {
    scanf("%d%d", &n, &t);
    sq = (int)sqrt(n);

    for(int i=1; i<=n; i++) scanf("%d", &arr[i]);
    for(int i=1; i<=t; i++) {
        scanf("%d%d", &Q[i].left, &Q[i].right);
        Q[i].index = i;
    }

    sort(Q+1, Q+t+1, cmp);

    int low = Q[1].left, high = Q[1].right;
    for(int i=low; i<=high; i++) {
        f(i, true);
    }
    ans[Q[1].index] = sum;

    for(int i=2; i<=t; i++) {
        while(Q[i].left < low) {
            f(--low, true);
        }
        while(Q[i].right > high) {
            f(++high, true);
        }
        while(Q[i].left > low) {
            f(low++, false);
        }
        while(Q[i].right < high) {
            f(high--, false);
        }
        ans[Q[i].index] = sum;
    }
    for(int i=1; i<=t; i++) {
        printf("%lld\n", ans[i]);
    }

    
}
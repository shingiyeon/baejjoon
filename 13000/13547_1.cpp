//# Author : nuclear852 ========================#
//# Solution : 23292978 ========================#
//# Time Stamp : 2020-10-16 23:26:44 ===========#
//# Problem Title : 수열과 쿼리 5 ===============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int N, M;
int cnt[1000001];
int arr[100001];
int ans[100001];
int disNum = 0;

struct query {
    int left, right, index;
} Q[100001];

bool cmp(const query& a, const query& b) {
    int sq = (int)sqrt(N);

    int aSR = a.right / sq;
    int bSR = b.right / sq;
    
    return aSR == bSR ? a.left < b.left : aSR < bSR;
}

void f(int index, bool add) {
    if(add) {
        if(cnt[arr[index]] == 0) {
            disNum++;
        }
        cnt[arr[index]]++;
    }
    else {
        cnt[arr[index]]--;
        if(cnt[arr[index]] == 0) {
            disNum--;
        }
    }
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &M);
    for(int i=1; i<=M; i++) {
        scanf("%d%d", &Q[i].left, &Q[i].right);
        Q[i].index = i;
    }
    sort(Q+1, Q+M+1, cmp);
    int lo = 1, hi = 0;
    for(int i=1; i<=M; i++) {
        while(Q[i].left < lo) {
            f(--lo, true);
        }
        while(Q[i].left > lo) {
            f(lo++, false);
        }
        while(Q[i].right > hi) {
            f(++hi, true);
        }
        while(Q[i].right < hi) {
            f(hi--, false);
        }
        ans[Q[i].index] = disNum;
    }

    for(int i=1; i<=M; i++) printf("%d\n", ans[i]);
}
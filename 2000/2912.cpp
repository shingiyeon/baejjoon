//# Author : nuclear852 ========================#
//# Solution : 23293632 ========================#
//# Time Stamp : 2020-10-16 23:54:47 ===========#
//# Problem Title : 백설공주와 난쟁이 ==============#
//# Language : C++14 ===========================#

#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int N, M, C;
int cnt[10001];
int arr[300001];
int ans[10001];

struct query {
    int left, right, index;
} Q[10001];

bool cmp(const query& a, const query& b) {
    int sq = (int)sqrt(N);

    int aSR = a.right / sq;
    int bSR = b.right / sq;
    
    return aSR == bSR ? a.left < b.left : aSR < bSR;
}

void f(int index, bool add) {
    if(add) {
        cnt[arr[index]]++;
    }
    else {
        cnt[arr[index]]--;
    }
}

int main() {
    scanf("%d%d", &N, &C);
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

        int j;
        for (j = 1; j <= C; j++) {
            if(cnt[j] >= (Q[i].right - Q[i].left + 1) / 2 + 1) {
                break;
            }
        }
        if(j<=C)
            ans[Q[i].index] = j;
    }

    for(int i=1; i<=M; i++) {
        if(!ans[i]) {
            printf("no\n");
        } else{
            printf("yes %d\n", ans[i]);
        }
    } 
}